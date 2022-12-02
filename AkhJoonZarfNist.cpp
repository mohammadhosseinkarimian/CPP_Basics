import hashlib
import math
import sys
import gmpy2
import unittest
from gmpy2 import c_div
from gmpy2 import isqrt
from sympy import *
import random

# Creating a random for generating key in RSA
rnd = random.SystemRandom()


# Continued Fraction's convergence
def conv(public_key_e):
    # List of denominators and nominators for the convergence
    d_noms = []
    n_noms = []
    for i in range(len(public_key_e)):
        if i > 1:
            d_val = d_noms[i - 2] + d_noms[i - 1] * public_key_e[i]
            n_val = n_noms[i - 2] + n_noms[i - 1] * public_key_e[i]
        elif i == 1:
            d_val = public_key_e[i]
            n_val = public_key_e[i - 1] * public_key_e[i] + 1
        elif i == 0:
            d_val = 1
            n_val = public_key_e[i]

        n_noms.append(n_val)
        d_noms.append(d_val)
        yield (n_val, d_val)


def prim_create(lngth):
    while 1:
        variable = rnd.getrandbits(lngth)
        boolean = gmpy2.is_prime(variable)
        if boolean:
            return variable


def continuedFraction(public_key_n, private_key_d):
    # second_prime_q is a prime number that it multiplation with first_prime_p is equal to public_key_n
    # public_key_n and public_key_e are our public keys resemboling n and e in RSA algorithm
    second_prime_q = math.floor(public_key_n / private_key_d)
    public_key_e = []
    public_key_e.append(second_prime_q)
    variable = public_key_n % private_key_d
    while variable != 0:
        public_key_n = private_key_d
        private_key_d = variable
        variable = public_key_n % private_key_d
        temp_var = math.floor(public_key_n / private_key_d)
        second_prime_q = temp_var
        public_key_e.append(second_prime_q)
    return public_key_e


def create_keypair(lngth):
    while True:
        p = prim_create(lngth // 2)
        second_prime_q = prim_create(lngth // 2)
        if second_prime_q < p < 2 * second_prime_q:
            break

    public_key_n = p * second_prime_q
    phi_N = (p - 1) * (second_prime_q - 1)

    # Recall that: private_key_d < (public_key_n^(0.25))/3
    max_d = c_div(isqrt(isqrt(public_key_n)), 3)
    max_d_bits = max_d.bit_length() - 1

    while True:
        private_key_d = rnd.getrandbits(max_d_bits)
        try:
            public_key_e = int(gmpy2.invert(private_key_d, phi_N))
        except ZeroDivisionError:
            continue
        if (public_key_e * private_key_d) % phi_N == 1:
            break
    key_tst = (public_key_n - 123) >> 7==pow(pow((public_key_n - 123) >> 7, public_key_e, public_key_n),
                                             private_key_d, public_key_n)
    assert key_tst

    return public_key_n, public_key_e, private_key_d, p, second_prime_q


def sha1(public_key_n):
    h = hashlib.sha1()
    h.update(str(public_key_n).encode('utf-8'))
    return h.hexdigest()


class ContinuedFractionsTests(unittest.TestCase):
    def test_cf_expansion(self):
        expected = [0, 5, 29, 4, 1, 3, 2, 4, 3]
        self.assertTrue(continuedFraction(17993, 90581) == expected)

    def test_convergents(self):
        cf_expansion = [0, 5, 29, 4, 1, 3, 2, 4, 3]
        expected = [(0, 1), (1, 5), (29, 146), (117, 589), (146, 735),
                    (555, 2794), (1256, 6323), (5579, 28086), (17993, 90581)]
        self.assertTrue(conv(cf_expansion))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    public_key_n, public_key_e, private_key_d, p, second_prime_q = create_keypair(1024)
    print('[+] Generated an RSA keypair with a short private exponent.')
    print('[+] For brevity, keypair components are crypto. hashed:')
    print('[+] ++ SHA1(public_key_e):    ', sha1(public_key_e))
    print('[+] -- SHA1(private_key_d):    ', sha1(private_key_d))
    print('[+] ++ SHA1(public_key_n):    ', sha1(public_key_n))
    print('[+] -- SHA1(p):    ', sha1(p))
    print('[+] -- SHA1(second_prime_q):    ', sha1(second_prime_q))
    print('[+] -- SHA1(phiN): ', sha1((p - 1) * (second_prime_q - 1)))
    print('[+] ------------------')

    cf_expansion = continuedFraction(public_key_e, public_key_n)
    convergents = conv(cf_expansion)
    print('[+] Found the continued fractions expansion convergents of public_key_e/public_key_n.')

    print('[+] Iterating over convergents; '
          'Testing correctness through factorization.')
    print('[+] ...')
    for pk, pd in convergents:  # pk - possible k, pd - possible private_key_d
        if pk == 0:
            continue;

        possible_phi = (public_key_e * pd - 1) // pk

        p = Symbol('p', integer=True)
        roots = solve(p ** 2 + (possible_phi - public_key_n - 1) * p + public_key_n, p)

        if len(roots) == 2:
            pp, pq = roots  # pp - possible p, pq - possible second_prime_q
            if pp * pq == public_key_n:
                print('[+] Factored public_key_n! :) derived keypair components:')
                print('[+] ++ SHA1(public_key_e):    ', sha1(public_key_e))
                print('[+] ++ SHA1(private_key_d):    ', sha1(pd))
                print('[+] ++ SHA1(public_key_n):    ', sha1(public_key_n))
                print('[+] ++ SHA1(p):    ', sha1(pp))
                print('[+] ++ SHA1(second_prime_q):    ', sha1(pq))
                print('[+] ++ SHA1(phiN): ', sha1(possible_phi))
                sys.exit(0)

    print('[-] Wiener\'s Attack failed; Could not factor public_key_n')
    sys.exit(1)


