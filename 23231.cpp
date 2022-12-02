#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int takhte[4][4];
int dirline[]={1,0,-1,0};
int dircolumn[]={0,1,0,-1};
pair<int,int> g(){
	int oc=1,line,column;
	while(oc){
	 line =rand()%4;
	column =rand()%4;
		if(takhte[line][column]==0);
		oc=0;
	}
	return make_pair(line,column);
}
void ezafekardan(){
		pair<int,int>makan=g();
	takhte[makan.first][makan.second]=2;
}
void bazijadid (){
	for(int i=0;i<4;++i)
	for(int j=0;j<4;++j)
	takhte[i][j]=0;
 ezafekardan();
}

void bazi(){
	system("cls");
		cout<<"2048 GAME "<<endl;
	cout<<"BY:Mahdi Esmaeily and Arefeh Firouzeh"<<endl;

	for (int i=0;i<4;i++){
	for (int j=0;j<4;j++)
	
	if(takhte[i][j]==0)
	cout<<setw(4)<<".";
	else 
	cout<<setw(4)<<takhte[i][j];
	cout<<"\n";
}
}
bool emkanharekat(int line,int column,int nextline,int nextcolumn){
	if (nextline <0||nextcolumn<0||nextline >=4||nextcolumn >=4
	||(takhte[line][column]!=takhte[nextline][nextcolumn]&&takhte[nextline][nextcolumn]!=0))
	return false;
return true;
}
void harekat(int direction){
	int startline =0,startcolumn=0,linestep=1,columnstep=1;
	if(direction==0){
	startline =3;
	linestep=-1;
}
if(direction==1){
	startcolumn=3;
	columnstep=-1;
}
int emkaneharekat,emkaneezafekardan=0;
do{
	emkaneharekat=0;

	for (int i=startline;i>=0&&i<4;i+=linestep)
	for (int j=startcolumn;j>=0&&j<4;j+=columnstep){
		int nexti=i+dirline[direction],nextj= j+dircolumn[direction];
	if	(takhte[i][j]&&emkanharekat(i,j,nexti,nextj)){
		takhte[nexti][nextj]+=takhte[i][j];
		takhte[i][j]=0;
		emkaneharekat=emkaneezafekardan=1;
	}
	}
}while (emkaneharekat);
if (emkaneezafekardan)	
ezafekardan();
}


int main()
{

	char jahat[100];
	jahat['s']=0;
	jahat['d']=1;
	jahat['w']=2;
	jahat['a']=3;
	bazijadid();

	while(true){
	bazi();
	char command;
	cin>>command;
	if(command=='n')
	bazijadid();
	else if (command=='q')
	break;
	else {
		int currentdirection =jahat[command];
		harekat(currentdirection);
		}
	}
	
}