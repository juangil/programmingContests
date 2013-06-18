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

struct member{
    string name;
    int preference;
    int pos;
};

bool myCmp (member a,member b) {
     if(a.preference != b.preference ) return a.preference < b.preference;
     else return a.pos < b.pos;
}


int main(){
    int n;
    cin >> n;
    vector<member> myCrew;
    map<string, int > myMap2;
    myMap2["rat"] = 0; 
    myMap2["woman"] = 1;
    myMap2["child"] = 1;
    myMap2["man"] = 3;
    myMap2["captain"] = 4;
    FR(i,n){
       string n,m;
       cin >> n >> m;
       member mem;
       mem.name = n;
       mem.preference = myMap2[m];
       mem.pos = i;
       myCrew.PB(mem);
    }
    sort(myCrew.begin(), myCrew.end(), myCmp);
    FR(i,n){
       cout<<myCrew[i].name<<endl;
    }
    return 0;
}
      
