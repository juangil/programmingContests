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
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;
typedef map<int,int> mii;
typedef vector< pii > vpi;
 
bool myCmp (int a, int b) { return (a < b); } 

vi switchedOn;
int myFac [10001];
int myPow [10001];

        
int main()
{
    int n,m;
    myFac[0] = 1;
    myFac[1] = 1;
    myPow[0] = 1;
    myPow[1] = 2;     
    fr(i,2,10000){
       myFac[i] = ((i*myFac[i-1])%1000000007);
       myPow[i] = ((2*myPow[i-1])%1000000007);
    }
    cin >> n >> m;
    int light;
    FR(i,m){  
       cin >> light;
       switchedOn.PB(light);
    }
    sort(rall(switchedOn), myCmp);
    int cont = 0;
    int result = 0;
    if(switchedOn[0] != 1)
       cont = 1;
    if(switchedOn[switchedOn.size()] != n)
       cont += 1;
    
    int nswitchesoff = 0;
    vi switchedOff;
    fr(i,1,switchedOn.size()){
        nswitchesoff = switchedOn[i] - switchedOn[i-1] - 1;
        cont += nswitchesoff; 
        switchedOff.PB(nswitchesoff);
        result *= myPow[nswitchesoff];
    }    
    int result1 = myFac[cont];
    int result2 = 1.0;
    FR(i,switchedOff.size())      
        result2 = (result2*(myFac[switchedOff[i]]));
    
    cout<<(result/result2)*result<<endl;
    return 0;
  
}
