# include <bits/stdc++.h>

using namespace std;
const int MAXN = 2002;
int N;
vector< vector<int> > G(MAXN);

struct edge{
    int u;
    int v;
    int w;
    
    edge(){}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const edge& other) const {
        return w > other.w;
    }
};

bool bfsFrom(int ini, int goal){
    int visited[N];
    for(int i = 0; i < N; ++i) visited[i] = 0;
    queue<int> Q;
    Q.push(ini);
    while(!Q.empty()){
        int actual = Q.front(); Q.pop();
        if(actual == goal) return true;
        visited[actual] = 1;
              
        for(int i = 0;i < G[actual].size(); ++i)
            if(!visited[G[actual][i]])Q.push(G[actual][i]);
    
    }
    return false;
}

int main(){
    int n;
    while(cin >> n){
        N = n;
        priority_queue<edge> my_edges;
        int menor  = (1 << 30);
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 0; i < n; ++i){
            int flag = false;
            for(int j = 0; j < n; ++j){
                int a; cin >> a;
                if(a == 0 && !flag) flag = true;
                if(flag && (i != j)){
                    edge e = edge(i,j,a);
                    my_edges.push(e);
                    menor = min(a,menor);
                }
            }
        }
        vector<edge> new_edges;
        while(!my_edges.empty()){
            edge actual = my_edges.top();
            my_edges.pop();
            if(actual.w == menor){
                G[actual.u].push_back(actual.v);
                G[actual.v].push_back(actual.u);
                //cout<<"creo: "<<actual.u<<" "<<actual.v<<" "<<G[actual.u].size()<<endl;
                new_edges.push_back(actual);
            }
            else{
                //cout<<"miro: "<<actual.u<<" "<<actual.v<<" "<<bfsFrom(actual.u, actual.v)<<endl;
                if(!bfsFrom(actual.u, actual.v)){
                    G[actual.u].push_back(actual.v);
                    G[actual.v].push_back(actual.u);
                    new_edges.push_back(actual);
                }
            }                
        }
        for(int i = 0; i < new_edges.size(); ++i)
            cout<<new_edges[i].u + 1<<" "<<new_edges[i].v + 1<<" "<<new_edges[i].w<<endl;
        cout<<endl;
    }
    return 0;

}
