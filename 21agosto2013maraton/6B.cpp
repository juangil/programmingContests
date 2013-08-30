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

bool mycmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){return a.second < b.second;}
    else return a.first < b.first;
}

int main(){
    int n, m;
    char a;
    cin >> n >> m >> a;
    char office [n+10][m+10];
    FR(i,n){
        FR(j,m)
            cin >> office[i][j];
    }
    vector< pair<int,int> > desk;
    FR(i,n){
        FR(j,m){
            if(office[i][j] == a)
                desk.PB(MK(i,j));
        }
    }
    sort(all(desk), mycmp);
    pair<int,int> minlim = desk[0];
    pair<int,int> maxlim = desk[desk.size() - 1];
    set<int> myset;
    for(int i = minlim .first - 1; i <= maxlim.first + 1; ++i){
        for(int j = minlim .second - 1; j <= maxlim.second + 1; ++j){
            bool c1 = (i == minlim .first - 1 and j == minlim .second - 1);
            bool c2 = (i == maxlim.first + 1 and j == minlim .second - 1);
            bool c3 = (i == minlim .first - 1 and j == maxlim.second + 1);
            bool c4 = (i == maxlim.first + 1 and j == maxlim.second + 1);
            if(i < 0 || j < 0 || i >= n || j >= m || c1 || c2 || c3 || c4) continue;
            //cout<<office[i][j]<<" ";
            if(office[i][j] != '.' and office[i][j] != a) myset.insert(office[i][j]);
        }
        //cout<<endl;
    }
    cout<<myset.size()<<endl;
    return 0;
}
