# include <bits/stdc++.h>

using namespace std;

const int MAXNODES = 1000;

vector< vector<int> > G(MAXNODES);
int weight [MAXNODES];
int parent [MAXNODES];
int dp[MAXNODES][2];

/* Recursion for solving the problem of finding a maximum weighted independent subset (MWIS)
   and IS is a subset of a graph G where there is no edge between any pair of vertex
   ind IS*/
int maxWeightFrom(int node, bool selected){
    if(dp[node][selected] != -1) return dp[node][selected];
    if(G[node].size() == 1 && !selected) return 0;
    if(G[node].size() == 1 && selected) return weight[node];
    
    int ans = 0;
    if(selected){
        ans += weight[node];
        int tmp = 0;
        for(int i = 0; i < G[node].size(); ++i)
                if(G[node][i] != parent[node]){
                    parent[G[node][i]] = node;
                    ans += maxWeightFrom(G[node][i], false);
                }
    }
    else{
        int tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < G[node].size(); ++i){
                if(G[node][i] != parent[node]){
                    parent[G[node][i]] = node;
                    tmp1 = maxWeightFrom(G[node][i], false);
                    tmp2 = maxWeightFrom(G[node][i], true);
                    ans += max(tmp1, tmp2);
                }
        }
                
    }
    return dp[node][selected] = ans;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
        parent[i] = -1;
        G[i].clear();
    }
    for(int i = 0; i < n - 1; ++i){
        int u,v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 2; ++j)
            dp[i][j] = -1;
    
    int ans = max(maxWeightFrom(0,0), maxWeightFrom(0,1));
    cout<<"The tree Maximum Weighted Independent Set weights: "<<ans<<endl;
    return 0;
}
