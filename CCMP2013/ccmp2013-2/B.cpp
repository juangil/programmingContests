using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include <limits> 
#include <queue> 
#include <stack> 
#include <set>
#include <map>
#include <cstring> 
#define MP 5005
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,v) for( typeof (v.begin()) x = v.begin();x!=v.end();++x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 1001
#define MC 101

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;


struct node{
    int id;
    int cap;    
    node(){}
    node(int I,int C): id(I),cap(C){}
    bool operator < (const node &o) const{
        if(id == o.id){
            return cap < o.cap;
        }
        return id < o.id;
    }
};

struct edge{
  int to,weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

struct state{
    int x,y,val;
    state(){}
    state(int X,int Y):x(X),y(Y),val(0){}
    bool operator < (const state &o) const{
        return val > o.val;
    }
    
};

typedef map<int , vector<edge> >  graph;


int c[MN][MC]; 

int price[MN];
int cap;
const int inf = (1<<29);

graph g;

int dijkstra(int s, int t, int n){
  //s = nodo inicial, n = número de nodos
  for (int i=0; i<n; ++i)
    for(int j = 0;j<MC; ++j)
        c[i][j] = inf;
  
  c[s][0] = 0;
  priority_queue<state> q;
  q.push(state(s, 0));
  while (!q.empty()){
    int ciudad = q.top().x;
    int capacidad = q.top().y;
    int val  = q.top().val;
    q.pop();

    if (val > c[ciudad][cap]) continue;
    if (ciudad == t){
      return val;
    }
    
    if(capacidad < cap){
        state otro(ciudad,capacidad+1);
        otro.val = val + price[ciudad];
        if(c[otro.x][otro.y] > otro.val){
            c[otro.x][otro.y] =  otro.val;
            q.push(otro);
        }
    }
    
    for (int i=0; i<g[ciudad].size(); ++i){
      int to = g[ciudad][i].to;
      
      if(g[ciudad][i].weight <= capacidad){
         state nuevo(to,capacidad - g[ciudad][i].weight);
         nuevo.val = val;
         if(c[nuevo.x][nuevo.y] > nuevo.val){
            c[nuevo.x][nuevo.y] = nuevo.val;
            q.push(nuevo);
         }      
      }
    }
  }
  return inf;
}

int main(){
    int n,m;
    cin>>n>>m;
    For(i,n){
        cin>>price[i];
    }
    int u,v,w;
    For(i,m){
        cin>>u>>v>>w;
        g[u].push_back(edge(v,w));
        g[v].push_back(edge(u,w));
    }
    int q;cin>>q;
    int s,t;
    while(q--){
        cin>>cap>>s>>t;    
        int ans = dijkstra(s,t,n);
        if (ans == inf)cout<<"impossible"<<endl;
        else cout<<ans<<endl;
        
    }
    
    return 0;
}
