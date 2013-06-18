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
//#include<istream>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
# include <sstream>

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

bool mycmp (int a,int b) { return a<b; }
bool mycmp2 (int a,int b) { return a>b; }

int main()
{
   int n,m;
   cin >> n >> m;
   int A[n][m];
   string ass;
   FR(i,n){
     cin>>ass;
     FR(j,m)
        A[i][j] = ass[j]-'0';
   }
   int n2,m2;
   cin >> n2 >> m2;
   int B[n2][m2];
   FR(i,n2){
      cin >> ass;
      FR(j,m2)
        B[i][j] = ass[j] - '0';
   }
   
   int mayor = -10000000;
   pair<int,int> mio;
   fr(x,-51,51){
     fr(y,-51,51){
      int total = 0;
       FR(i,n){
          FR(j,m){
             if((i+x >= 0 && i+x < n2) && (j+y >= 0 && j+y < m2) )
             {
                total += (A[i][j])*(B[i+x][j+y]);
                if(total > mayor){
                   mayor = total;
                   mio.first = x;
                   mio.second = y;
                }
              }
          }            
       }
      }
    }
    cout << mio.first << " " << mio.second <<endl;
    return 0;
}
             
             
    
