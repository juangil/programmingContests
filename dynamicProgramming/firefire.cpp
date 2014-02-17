# include <bits/stdc++.h>

using namespace std;

const int MAXNODES = 1002;

vector< vector<int> > G(MAXNODES);
int weight [MAXNODES];
int parent [MAXNODES];
int dp[MAXNODES][2];


int minExitsFrom(int node, bool selected){
    if(dp[node][selected] != -1) return dp[node][selected];
    if(G[node].size() == 1 && selected) return 1;
    if(G[node].size() == 1 && !selected) return 0;
    
    int ans = 0;
    if(selected){
        //ans += 1;
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < G[node].size(); ++i){
            if(G[node][i] != parent[node]){
                parent[G[node][i]] = node;
                minExitsFrom(G[node][i], false);
                ans1 += minExitsFrom(G[node][i], true);
            }
        }
        ans += ans1;
    }
    else{
        for(int i = 0; i < G[node].size(); ++i){
            if(G[node][i] != parent[node]){
                parent[G[node][i]] = node;
                minExitsFrom(G[node][i], true);
            }
        }
    }
    return dp[node][selected] = ans;
}


int main(){
    int n;
    while(cin >> n && n){
        for(int i = 0; i < n; ++i){
            parent[i] = -1;
            weight[i] = 1;
            G[i].clear();
        }
        for(int i = 0; i < n; ++i){
            int m; cin >> m;
            for(int j = 0; j < m; ++j){
                int v; cin >> v;
                G[i].push_back(v-1);
            }
        
        }
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 2; ++j)
                dp[i][j] = -1;
    
        int ans = max(minExitsFrom(0,0), minExitsFrom(0,1));
        cout<<n - ans<<endl;
        
    }
    return 0;
}
