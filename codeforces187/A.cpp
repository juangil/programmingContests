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


bool esta(map<int, vector<int> > mymap, int a){
     std::map<int, vector<int> >::iterator it;
     for(it = mymap.begin();it != mymap.end(); it++){
          //cout<<it->first<<" "<<a<<endl; continue;
          if(it->first == a) return true;
     }
     return false;
}
bool esta2(map<int, vector<int> > mymap, int a){
     std::map<int, vector<int> >::iterator it;
     int cont = 0;
     for(it = mymap.begin();it != mymap.end(); it++){
          cout<<it->first<<" "<<a<<endl; 
          if(it->first == a) cont++;
     }
     cout<<cont<<endl;
     if(cont >= 2)return true;
     else return false;
}

int main(){
     int n;
     cin >> n;
     map<int, vector<int> > myBottles;
     map<int,int> canOpen;
     int mayor = -1;
     FR(i,n){
          int a,b;
          cin >> a >> b;
          myBottles[a].PB(b);
     }
     std::map<int, vector<int> >::iterator it;
     for(it = myBottles.begin();it != myBottles.end(); it++){
          //cout<<it->first<<it->second.size()<<endl;;
          FR(j, it->second.size()){
               if(it->first == it->second[j]){
                    cout<<"pass1"<<endl;
                    if(esta2(myBottles, it->second[j])){               
                         canOpen[it->second[j]] = 1;cout<<"pass"<<endl;}
               }
               else if(esta(myBottles, it->second[j])){
                    canOpen[it->second[j]] = 1;
               }
          }
          cout<<endl;
     }
     int cont = 0;   
     std::map<int, int>::iterator it2;
     for(it2 = canOpen.begin(); it2 != canOpen.end(); it2++){
          //cout<<it2->first<<" "<<myBottles[it->first].size()<<endl;//myBottles[it->first].size()<<endl;
          cont += myBottles[it2->first].size();
     }     
     //cout<<cont<<endl;
     cout<<n - cont<<endl;
     return 0;
}
          










