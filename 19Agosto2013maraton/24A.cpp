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

const double EPS = 1e-7;

int bfs(int ini, int dir, vector< vector< pair<int,int> > > &G){
    queue< int > Q;
    vector<int> visited (G.size(),0);
    int ans = 0;
    Q.push(ini);
    while(!Q.empty()){
        int actual = Q.front();
        Q.pop();
        if(visited[actual]) continue;
        visited[actual] = 1;
        if(actual == ini){
            if(G[actual][dir].second < 0) ans += G[actual][dir].second;
            if(G[actual][!dir].second > 0) ans -= G[actual][!dir].second;
            Q.push(G[actual][dir].first);        
        }
        else{
            if(!visited[G[actual][0].first]){
                if(G[actual][0].second < 0) ans += G[actual][0].second;
                Q.push(G[actual][0].first);
            }
            else if(!visited[G[actual][1].first]){
                if(G[actual][1].second < 0) ans += G[actual][1].second;
                Q.push(G[actual][1].first);
            }
        }
        
    }
    return ans;
}

int main(){
    int n, t = 0;
    cin >> n;
    vector< vector< pair<int,int> > > G(n);
    for(int i = 0; i < n; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        G[a - 1].push_back(make_pair(b - 1,c));
        G[b - 1].push_back(make_pair(a - 1,-c));
    }
    int ini = -1;
    for(int i = 0; i < n; ++i){
        if(G[i].size() == 2){ ini = i; break;}
    }
    int cost1 = -bfs(ini, 0, G);
    int cost2 = -bfs(ini, 1, G);
    cout<<min(cost1,cost2)<<endl;
    return 0;
}
