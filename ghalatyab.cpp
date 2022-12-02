#include <iostream>
#include <windows.h>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

#define size 8
#define X first
#define Y second
// black: 0, white: 1 , gray = 2, normal = 3

int color(int& marble, int& p) { //p = place
    if (marble == 0 && p == 0) return 128;// black on black
    if (marble == 0 && p == 1) return 112;// black on white
    if (marble == 1 && p == 0) return 142;// white on black
    if (marble == 1 && p == 1) return 126;// white on white
    if (marble == 2 && p == 0) return 132;// gray   on black
    if (marble == 2 && p == 1) return 116;// gray   on white
    if (marble == 2 && p == 3) return 4;  // gray  on normal
    if (marble == 3 && p == 3) return 7;  // normal
}

void set_color(int marble, int p) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color(marble, p));
}

class Chessp {
private:
    bool be_soldier_ = 0, can_go_ = 0, color_ = 0 ;
    char marble_ = ' ';

public:
    bool color() {return color_;}

    bool can_go() {return can_go_;}
    void can_go(bool k) {can_go_ = k;}
    bool be_soldier() {return be_soldier_;}
    void be_soldier(bool k) {be_soldier_ = k;}
    void marble(char k) {marble_ = k;}
    char marble() {return marble_;}
    void print(int p) {
        set_color(2, p);
        if (can_go_) cout << '['; else cout << ' ';
        set_color(color_ ,p);
        cout << marble_;
        set_color(2, p);
        if (can_go_) cout << ']'; else cout << ' ';
    }

    bool is_enemy(bool round) {
        if (marble_ != ' ' && color_ != round)return true;
        return false;
    }

    Chessp operator=( pair<char,bool> p) {
        marble_ = p.X;
        color_ = p.Y;
    }

    bool operator==(char i) {
        if (marble_ == i) return true;
        return false;
    }
};

class ChessGame{
	
private:
	int n_out_ = 0 , r_out_ = 0 , b_out_ = 0 , q_out_ = 0;

    Chessp chart[size][size];
    bool can_go, round = 1;// white: 1 , black: 0
    int choose_x = -1, choose_y = -1, winner = 2;

    map<char, int> box[2]; // box for player white and black

    string err_input = "";

    bool game_over() {
        if (winner == 2) return true;
        if (winner == 1)  cout << "\n-- Player white winner ! --\n";
        else if (winner == 0) cout << "\n-- Player black winner ! --\n";
        return false;
    }
    // -------------------- print
    void print_please_enter() {
        set_color(2, 3);
        cout << err_input;
        err_input = "";
        set_color(3, 3);
        cout << "\nwrite [R:"<<box[round]['R']<<" ,N:"<<box[round]['N']<<" ,B:"<<box[round]['B']<<", Q:"<<box[round]['Q']<<", P:"<<box[round]['P'];
        cout << "]\nin box or choice a p (like c5):";
    }

    void print_abc_h() {
        cout << "  ";
        for (int i = 0; i < size; i ++ ) {
            cout << " " << char(i + 'a') << " ";
        }
        cout << '\n';
    }

    void print_chart() {
        bool k = true;
        system("cls");
        print_abc_h();
        for (int i = 1; i <= size; i ++ ) {
            cout << i << " ";
            for (int j = 0; j < size; j ++ ) {
                chart[i - 1][j].print(k);
                k = !k;
            }
            set_color(3, 3);
            cout << " " << i << '\n';
            k = !k;
        }
        print_abc_h();
    }

    void print_game() {
        set_color(3, 3);
        print_chart();
        cout << "\n\n\nround:";
        if (round) set_color(1, 1);
        else set_color(0, 0);
        cout << "   ";
        set_color(3, 3);
        print_please_enter();
    }
    // -------------------- box
    pair<int,int> correct_p_can_go() {
        string a;
        do {
            cout << "";
            cin >> a;
        } while (!(a.length()==2&&a[0] <= 'h'&&a[0] >= 'a'&&a[1] <= '8'&&a[1] >= '1')
                 ||chart[a[1] - '1'][a[0] - 'a'].can_go()==0);
        return {a[1] - '1', a[0] - 'a'};
    }

    bool check_box(string& a) {
        if (a.length() == 1 && (a[0]=='p'||a[0]=='r'||a[0]=='n'||a[0]=='b'||a[0]=='q')) {
            a[0] = a[0] - 'a' + 'A';
            if (box[round][a[0]] == 0) err_input = "";
            else {
                box[round][a[0]] --;
                if (a[0] == 'P') {
                    int i = round ? 6 : 1;
                    for (int j = 0; j < size; j ++ ) if (chart[i][j] == ' ') chart[i][j].can_go(1);
                } else {
                    for (int i = 0; i < size; i ++ )
                        for (int j = 0; j < size; j ++ )
                            if (chart[i][j] == ' ') chart[i][j].can_go(1);
                }
                print_game();
                pair<int,int> b = correct_p_can_go();
                chart[b.X][b.Y] = {a[0], round};
                set_can_go_zero();
                round = !round;
            }
            return true;
        }
        return false;
    }
    // --------------------
    bool mark_move(int i, int j) {
        if (i < 0 || j < 0 || size <= i || size <= j) return false;
        if (chart[i][j] == ' ') {
            chart[i][j].can_go(1);
            can_go = true;
            return true;
        }
        if (chart[i][j].color() == !round) {
            chart[i][j].can_go(1);
            can_go = true;
            return false;
        }
        return false;
    }

    void choice_marble(int i, int j) {
        if (round == chart[i][j].color()) {
            can_go = false;
            int ti = i, tj = j; // target i & j

            switch (chart[i][j].marble()) {
            case 'P':{
                int p_round = round ? -1 : 1;
                if (round == 1 && i == 6 && chart[4][j] == ' ')chart[4][j].can_go(1);
                if (round == 0 && i == 1 && chart[3][j] == ' ')chart[3][j].can_go(1);
                if (chart[i + p_round][j] == ' ') {
                    chart[i + p_round][j].can_go(1);
                    can_go = true;
                }
                if (j != 0 && chart[i + p_round][j - 1].is_enemy(round)) {
                    chart[i + p_round][j - 1].can_go(1);
                    can_go = true;
                }
                if (j != size - 1 && chart[i + p_round][j + 1].is_enemy(round)) {
                    chart[i + p_round][j + 1].can_go(1);
                    can_go = true;
                }
            }break;case 'Q':case 'R':
                while (mark_move(++ ti, tj));  ti = i, tj = j;
                while (mark_move(-- ti, tj));  ti = i, tj = j;
                while (mark_move(ti, ++ tj));  ti = i, tj = j;
                while (mark_move(ti, -- tj));  ti = i, tj = j;
                if (chart[i][j] == 'Q') goto rokh;
            break;case 'N':
                mark_move(i + 2, j - 1);mark_move(i + 2, j + 1);
                mark_move(i - 2, j - 1);mark_move(i - 2, j + 1);
                mark_move(i + 1, j - 2);mark_move(i + 1, j + 2);
                mark_move(i - 1, j - 2);mark_move(i - 1, j + 2);
            break;case 'B':rokh:
                while (mark_move(++ ti, ++ tj));  ti = i, tj = j;
                while (mark_move(-- ti, -- tj));  ti = i, tj = j;
                while (mark_move(++ ti, -- tj));  ti = i, tj = j;
                while (mark_move(-- ti, ++ tj));
            break;case 'K':
                mark_move(i + 1, j - 1);mark_move(i + 1, j + 1);
                mark_move(i - 1, j - 1);mark_move(i - 1, j + 1);
                mark_move(i    , j - 1);mark_move(i    , j + 1);
                mark_move(i - 1, j    );mark_move(i + 1, j    );
            }
            if (!can_go) {
                err_input = "\n-- you choose incorrect ! --\n";
            } else {
                choose_x = i;
                choose_y = j;
            }
        } else {
            err_input = "\n-- you choose the incorrect p ! --\n";
        }
    }

    void upgrade_soldier(int& i, int& j) {
        if (chart[i][j] == 'P' && (i == 0 || i == size - 1)) {
            chart[i][j].be_soldier(1);
            set_color(2, 3);
            char tmp;
            do {
                cout << "\nsoldier upgrade to these possible choices : ";
				if(n_out_>0)
				{
					
					cout<<"n " ;
				}
				
				if(b_out_>0)
				{
					cout<<"b " ;
				}if(q_out_>0)
				{
					cout<<"q " ;
				}if(r_out_>0)
				{
					cout<<"r" ;
				}
				cout<<"\n";
				 cout<<"\nenter your choose :";
                cin >> tmp;
            } while (((tmp != 'r') || ((tmp == 'r' )&&(r_out_ == 0)))&& ((tmp != 'n') || ((tmp == 'n' )&&(n_out_ == 0))) &&((tmp != 'b') || ((tmp == 'b' )&&(b_out_ == 0))) && ((tmp != 'q') || ((tmp == 'q' )&&(q_out_ == 0))));
            chart[i][j].marble(tmp - 'a' + 'A');
        }
    }

    void set_can_go_zero() {
        for (int i = 0; i < size; i ++ )
            for (int j = 0; j < size; j ++ )
                chart[i][j].can_go(0);
    }

    void move_marble(int i, int j) {
        if (!chart[i][j].can_go()) {
            err_input = "\n-- please enter a red p that you can go --\n";
            return;
        }
        
        if (chart[i][j] == 'K') winner = round;
        else if (chart[i][j].marble() != ' ') {
            if (chart[i][j].be_soldier()) {
                box[round]['P'] ++;
            }
            else box[round][chart[i][j].marble()] ++;
        }
        
        if(chart[i][j].is_enemy(round))
        {
        	for(int k = 0; k<8;k++)
        	{
        	if (chart[i][k] == 'K') winner = round;
			if(chart[i][k] == 'N')
			{
				n_out_++;
			}
			if(chart[i][k] == 'R')
			{
				r_out_++;
			}
			if(chart[i][k] == 'B')
			{
				b_out_++;
			}
			if(chart[i][k] == 'Q')
			{
				q_out_++;
			}
			chart[i][k].marble(' ');
        	        
			chart[i][k].be_soldier(0); 
			if (chart[k][j] == 'K') winner = round;    		
			if(chart[k][j] == 'N')
			{
				n_out_++;
			}
			if(chart[k][j] == 'R')
			{
				r_out_++;
			}
			if(chart[k][j] == 'B')
			{
				b_out_++;
			}
			if(chart[k][j] == 'Q')
			{
				q_out_++;
			}
			chart[k][j].marble(' ');
        	        
			chart[k][j].be_soldier(0);    
			}
        

		}
        chart[i][j] = chart[choose_x][choose_y];
        chart[i][j].be_soldier( chart[choose_x][choose_y].be_soldier() );
        
        
        
        
        chart[choose_x][choose_y].marble(' ');
        chart[choose_x][choose_y].be_soldier(0);

        upgrade_soldier(i, j);
        set_can_go_zero();
        choose_x = -1;
        choose_y = -1;
        round = !round;
    }

public:
    ChessGame() {
        box[0].insert({'P', 0});box[1].insert({'P', 0});
        box[0].insert({'R', 0});box[1].insert({'R', 0});
        box[0].insert({'N', 0});box[1].insert({'N', 0});
        box[0].insert({'Q', 0});box[1].insert({'K', 0});
        box[0].insert({'B', 0});box[1].insert({'B', 0});
        chart[0][0] = {'R', 0};chart[0][7] = {'R', 0};
        chart[0][1] = {'N', 0};chart[0][6] = {'N', 0};
        chart[0][2] = {'B', 0};chart[0][5] = {'B', 0};
        chart[0][3] = {'Q', 0};chart[0][4] = {'K', 0};
        chart[7][0] = {'R', 1};chart[7][7] = {'R', 1};
        chart[7][1] = {'N', 1};chart[7][6] = {'N', 1};
        chart[7][2] = {'B', 1};chart[7][5] = {'B', 1};
        chart[7][3] = {'Q', 1};chart[7][4] = {'K', 1};
        for (int i = 0; i < 8; i ++ ) {
            chart[1][i] = {'P', 0};
            chart[6][i] = {'P', 1};
        }
    }

    void run() {
        string tmp;
        while (game_over()) {
            print_game();
            cin >> tmp;
            if (check_box(tmp)) {}
            else if (tmp[0] <= 'h'&&tmp[0] >= 'a'&&tmp[1] <= '8'&&tmp[1] >= '1') {
                if (choose_x == -1) {
                	
                    choice_marble(tmp[1] - '1', tmp[0] - 'a');
                } else {
                	
                    move_marble(tmp[1] - '1', tmp[0] - 'a');
                }
            } else {
                err_input = "\n-- Input type is incorrect. please enter charily ! --\n";
            }
        }
    }
};
int main ()
{
    ChessGame game;
    game.run();
}
