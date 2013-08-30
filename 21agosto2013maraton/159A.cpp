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

int main(){
    int n,d;
    cin >> n >> d;
    map<string, vector< pair<string,int> > > mymap;
    set< pair<string,string> > myset;
    for(int i = 0; i < n; ++i){
        string a,b;
        int c;
        cin >> a >> b >> c;
        mymap[a].push_back(make_pair(b,c));
    }
    foreach(x,mymap){
        FR(i,x->second.size()){
            pair<string,int> current = x->second[i];
            FR(j,mymap[current.first].size()){
                if(mymap[current.first][j].first == x->first){
                    int dif = abs(mymap[current.first][j].second - current.second);
                    if( dif <= d and dif > 0){
                        pair<string,string> tmp = make_pair(current.first,x->first);
                        pair<string,string> tmp2= make_pair(x->first,current.first);
                        if(myset.count(tmp) || myset.count(tmp2)) continue;
                        else{
                            myset.insert(make_pair(current.first,x->first));
                            break;
                        }
                    }
                }    
            }
        }
    }
    cout<<myset.size()<<endl;
    foreach(x,myset){
        pair<string,string> current = *x;
        cout<<current.first<<" "<<current.second<<endl;
    }
    return 0;
}
