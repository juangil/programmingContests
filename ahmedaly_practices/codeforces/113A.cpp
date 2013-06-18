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

bool mycmp (string i,string j) { return (i>j); }
bool mycmp2 (std::map<string,vs>::iterator a,std::map<string,vs>::iterator b) { return (a->second.size()>b->second.size()); }

vs players;
map<string,vs> pairs;
int main()
{
    int n,m;
    cin >> n >> m;
    FR(i,n){
       string a;
       string b;
       cin >> a ;
       players.PB(a);
    }    
    FR(i,m)
    {
       string a;
       string b;
       cin >> a >> b;
       pairs[a].PB(b);
    }
    sort(rall(players), mycmp);
    if(m == 0)
    {
         cout<<n<<endl;
         FR(i,n)
            cout<<players[i]<<endl;
         return 0;
    }
    sort(rall(pairs), mycmp2);
    
    /*std::map<string,vs>::iterator it;
    foreach(x,pairs)
    { 
      FR(j,players.size())
      {
          if(it.first == players[j])
             players.erase(players.begin() + j);
      }
    }
    cout<<players.size()<<endl;
    sort(rall(players), mycmp);
    FR(i,players.size())
      cout<<players[i]<<endl;*/
    return 0;
    
    
}
       
       
      
    
    
