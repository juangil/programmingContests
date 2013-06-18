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
typedef map<int,int> mii;
typedef long long int lli;

bool mycmp (pair<string,int> a,pair<string,int> b) { return (a.second<b.second); }

int main()
{
   int n,m;
   cin >> n >> m;
   vi myInts;
   mii myMap;
   int visited [100001];
   memset(visited,0,sizeof(visited));
   FR(i,n){
     int a;
     cin >> a;
     myInts.PB(a);
     myMap[a] += 1;
     //cout<<a<<" : "<<myMap[a]<<endl;
   }
   FR(i,m){
     int a,b,cont = 0;
     cin >> a >> b;     
     memset(visited,0,sizeof(visited));
     fr(j,a-1,b){
         if(!visited[myInts[j]]){
            if(myMap[myInts[j]] == myInts[j]) cont += 1;
            visited[myInts[j]] = 1;
         }
         else continue;
     }
     cout<<cont<<endl;
  }
  return 0;
}
         
     
   
   
