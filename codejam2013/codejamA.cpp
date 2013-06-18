using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vss;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;
typedef map<string,int> msi;
typedef long long int lli;

bool mycmp (pair<string,int> a,pair<string,int> b) { return (a.second<b.second); }

bool checkRows(char game[5][5], char a)
{
    map<int,int> mymap;
    mymap[0] = 0;mymap[1] = 0;mymap[2] = 0;mymap[3] = 0;
    //cout<<"rows : "<<endl;
    FR(i,4){
       FR(j,4){
       
          if(game[i][j] == a || game[i][j] == 'T'){
             //cout<<i<<" "<<j<<"  "; 
             mymap[i] += 1;}
       }
      // D(mymap[i]);      
    }
    if(mymap[0] == 4 || mymap[1] == 4 || mymap[2] == 4 || mymap[3] == 4)
       return true;
    else    
       return false;
}

bool checkColumns(char game[5][5], char a)
{
    map<int,int> mymap;
    mymap[0] = 0;mymap[1] = 0;mymap[2] = 0;mymap[3] = 0;
    //cout<<"Columns : "<<endl;
    FR(i,4){
       FR(j,4){
          if(game[j][i] == a || game[j][i] == 'T')
             mymap[i] += 1;
       }   
       //D(mymap[i]);    
    }
    if(mymap[0] == 4 || mymap[1] == 4 || mymap[2] == 4 || mymap[3] == 4)
       return true;
    else
       return false;
}

bool checkDiagonals(char game[5][5], char a)
{
    int cont1 = 0, cont2 = 0;
    //       cout<<"diagonal :"<<endl;
    FR(i,4){
       FR(j,4){
          if(i == j){
             if(game[i][j] == a || game[i][j] == 'T'){    
                //cout<<i<<" "<<j<<endl;                  
                cont1 += 1;}
          }      
       }
    }
    //cout<<"diagonal2 :"<<endl;
    for(int i = 3; i >= 0; i--){
       for(int j = 3; j >= 0; j--){         
             if((i == 0 && j == 3)||(i == 1 && j == 2)||(i == 2 && j == 1)||(i == 3 && j == 0)) {
                if(game[i][j] == a || game[i][j] == 'T'){
                   //cout<<i<<" "<<j<<endl;  
                   cont2 += 1;}
             }      
        }
    }
    if(cont1 == 4 || cont2 == 4)
       return true;
    else
       return false;
}


int main()
{
   int t;
   cin >> t;
   
   FR(j,t)
   {  
      char game [5][5]; 
      FR(i,4)   
         scanf("%s", &game[i]);
      int cont = 0;
      FR(i,4){
          FR(j,4){
            // cout<<game[i][j]<<endl;
             if(game[j][i] != '.')
                 cont += 1;
          }      
      }
      char winner;
      //cout<<checkRows(game,'X') <<" "<<  checkColumns(game,'X') <<" "<<  checkDiagonals(game,'X')<<endl;
      //cout<<checkRows(game,'O') <<" "<<  checkColumns(game,'O') <<" "<<  checkDiagonals(game,'O')<<endl;
      
      if(checkRows(game,'X') ||  checkColumns(game,'X') ||  checkDiagonals(game,'X') )
         cout<<"Case #"<<j+1<<": X won"<<endl;
      else if(checkRows(game,'O') ||  checkColumns(game,'O') ||  checkDiagonals(game,'O'))
         cout<<"Case #"<<j+1<<": O won"<<endl;
      else if(cont < 16)
         cout<<"Case #"<<j+1<<": Game has not completed"<<endl;
      else if(cont == 16)
         cout<<"Case #"<<j+1<<": Draw"<<endl;
   }
   return 0;
}
      
   



