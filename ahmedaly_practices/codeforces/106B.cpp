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

struct pc{
    int speed;
    int ram;
    int hdd;
    int price;
    int id;
};

bool myCmp (pc a,pc b) {return a.price < b.price;}

int main(){
    int n;
    cin >> n;
    vector<pc> myPc;
    FR(i,n){
       int a,b,c,d;
       cin >> a >> b >> c >> d;
       pc p;
       p.speed = a; p.ram = b; p.hdd = c; p.price = d; p.id = i+1;
       myPc.PB(p);
    }
    vector<int> oudated;
    FR(i,n){
       FR(j,n){
           if( (myPc[i].speed < myPc[j].speed) && (myPc[i].ram < myPc[j].ram) && (myPc[i].hdd < myPc[j].hdd) ){
              oudated.PB(i+1);
              break;
           }
       }
    }
    vector<pc> myGood;
    FR(i,myPc.size()){
       bool flag = true;
       FR(j,oudated.size()){
         if(myPc[i].id == oudated[j]) flag = false;
       }
       if(flag) myGood.PB(myPc[i]);
    }
    sort(all(myGood), myCmp);
    cout<<myGood[0].id<<endl;
    return 0;
                                  
}
      
