# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
using namespace std;
typedef long long int lli;

const int MAXN = 55555;

lli dist2root [MAXN];
int L[MAXN]; // the level of a node in the tree
int P[MAXN]; // the last parent of a node i in the section before
int T[MAXN]; // the parent of a node i in the tree
int nr; // Where does start the firste section of the tree

void fillDistance2Root(vector< vector< pair<int,int> > > &G){
   vector<int> visited (G.size(), 0);
   queue< pair<int,int> > Q;
   Q.push(make_pair(0, 0));
   dist2root[0] = 0;
   L[0] = 0; //level of the node in the tree
   int tmp = 0;
   while(!Q.empty()){
      pair<int,int> actual = Q.front();
      Q.pop();
      if(visited[actual.first])continue;
      visited[actual.first] = 1;
      vector< pair<int,int> > children =  G[actual.first];
      for(int i = 0; i < children.size(); ++i)     
              if(!visited[children[i].first]){
                    dist2root[children[i].first] = dist2root[actual.first] + children[i].second;
                    L[children[i].first] = L[actual.first] + 1;
                    T[children[i].first] = actual.first;
                    Q.push(make_pair(children[i].first, actual.second + children[i].second));
               }
       }
                    
}
void bfs(vector< vector< pair<int,int> > > &G){// this the bfs for process the tree and 2 obtain P
     vector<int> visited (G.size(), 0);
     queue<int> Q;
     Q.push(0);
     while(!Q.empty()){
          int node = Q.front();
          Q.pop();
          if(visited[node]) continue;
          visited[node] = 1;
          if(L[node] < nr)
               P[node] = 1;
          else if(!(L[node]%nr))
               P[node] = T[node];
          else
               P[node] = P[T[node]];
          for(int i = 0; i < G[node].size(); ++i)
               Q.push(G[node][i].first);
          }
}
          
int LowestCA(int x, int y){
     while(P[x] != P[y]){
          if(L[x] > L[y])
               x = P[x];
          else
               y = P[y];
     }
     while(x != y){
          if(L[x] > L[y])
               x = T[x];
          else
               y = T[y];
     }
     return x;
}
int main(){
     int n;
     while(cin >> n){
          vector< vector< pair<int,int> > > G (n);
          nr = sqrt(n);
          memset(T,-1,sizeof T);
          for(int i = 0; i < n - 1; ++i){
               int u,v,w;
               cin >> u >> v >> w;
               G[u].push_back(make_pair(v,w));
               G[v].push_back(make_pair(u,w));
          }
          fillDistance2Root(G);
          bfs(G);
          int q; cin >> q;
          for(int i = 0; i < q; ++i){
               int a,b;
               cin >> a >> b;
               cout<<(dist2root[a] + dist2root[b] - 2*(dist2root[LowestCA(a,b)]))<<endl;
          }
     }
     return 0;
} 
