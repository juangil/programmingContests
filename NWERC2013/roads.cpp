# include <bits/stdc++.h>

using namespace std;
const int MAXN = 2002;
int N; int origen;
int my_cost[MAXN][MAXN];
int p[MAXN];
int visited [MAXN];
int minsum = (1<<30);

int find_set(int x) {
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}

void link(int x, int y) {
    p[find_set(x)] = p[find_set(y)];
}

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

vector< vector<int> > G(MAXN);
vector<edge> new_edges;
edge min_edge = edge(-1,-1,(1<<30));

void dfs(int ini, int sum){
    //cout<<origen+1<<" "<<ini+1<<" "<<sum<<" "<<my_cost[origen][ini]<<" ";
    if(my_cost[origen][ini] < sum && origen != ini && sum < minsum){
        minsum = sum;
        min_edge = edge(origen, ini, my_cost[origen][ini]);
    }
    
     
    visited[ini] = 1;
    for(int i = 0; i < G[ini].size(); ++i)
        if(!visited[G[ini][i]]) dfs(G[ini][i], sum + my_cost[ini][G[ini][i]]);
    return;
}

int main(){
    int n;
    bool primero = true;
    while(cin >> n){
        if (!primero)
            cout << endl;
        primero = false;
        N = n;
        priority_queue<edge> my_edges;
        int menor  = (1 << 30);
        min_edge = edge(-1,-1,(1<<30));
        new_edges.clear();
        for(int i = 0; i < n; ++i){
            G[i].clear();//limpiamos todo lo que vamos a utilizar
            p[i] = i;
        }
        for(int i = 0; i < n; ++i){
            int flag = false;
            for(int j = 0; j < n; ++j){
                int a; cin >> a;
                my_cost[i][j] = a;//la matriz de costo inicial
                if(a == 0 && !flag) flag = true;
                if(flag && (i != j)){//esto es simplemente para leer las aristas despues del cero
                    edge e = edge(i,j,a);
                    my_edges.push(e);//creamos una cola de prioridad donde mantenemos el menor en el tope
                    menor = min(a,menor);
                }
            }
        }
        
        while(new_edges.size() < n - 1){//vamos a crear aristas hasta que tengamos n -1
            edge actual = my_edges.top();
            my_edges.pop();
            G[actual.u].push_back(actual.v);
            G[actual.v].push_back(actual.u);
            new_edges.push_back(actual);
            link(actual.u, actual.v);
        }
        
        minsum = (1<<30);
        for(int i = 0; i < n; ++i){
            origen = i;//vamos a correr un dfs desde cada nodo origen (global)para mirar si hay rutas incosistentes con la matriz de costo inicial
            for(int j = 0; j < n; ++j) visited[j] = 0;
            dfs(i,0);
        }
        //cout<<my_cost[min_edge.u][min_edge.v]<<endl;
        if(min_edge.u != -1 && min_edge.v != -1 && min_edge.w != (1<<30)) new_edges.push_back(min_edge);
        if(new_edges.size() == n - 1) new_edges.push_back(new_edges[0]);
        for(int i = 0; i < new_edges.size(); ++i)
            cout<<new_edges[i].u + 1<<" "<<new_edges[i].v + 1<<" "<<new_edges[i].w<<endl;
                
        //cout<<endl;
    }
    return 0;

} 