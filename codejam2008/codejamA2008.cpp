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

bool mycmp (int a,int b) { return (a>b); }
bool mycmp2 (int a,int b) { return (a<b); }

vector< pair<string,int> >  table;

int main()
{
    int t;
    cin >> t;
    FR(j,t)
    {
       lli n,x,y;
       cin >> n;
       vi v1;
       vi v2;
       FR(i,n)
       {
           cin >> x;
           v1.PB(x);
       }
       FR(i,n)
       {
           cin >> y;
           v2.PB(y);
       }
       sort(rall(v1),mycmp);
       sort(rall(v2),mycmp2);
       lli result = 0;
       FR(i,n)       
          result += (v1[i] + 0LL)*v2[i];
          //D(v1[i]); D(v2[i]);}
       cout<<"Case #"<<j+1<<": "<<result<<endl;
    }
    return 0;
}
    
            
           
           
           
           
           
           
           
           
    
