# include <bits/stdc++.h>

using namespace std;

const int MAXNODES = 1002;

vector< vector<int> > G(MAXNODES);
int weight [MAXNODES];
int parent [MAXNODES];
int dp[MAXNODES][2];


int minExitsFrom(int node, bool selected){
    if(dp[node][selected] != -1) return dp[node][selected];
    //if(G[node].size() == 1 && selected) return 1;
    //if(G[node].size() == 1 && !selected) return 0;
    
    int ans = 0;
    if(selected){
        ans = 0;
        for(int i = 0; i < G[node].size(); ++i){
            if(G[node][i] != parent[node]){
                parent[G[node][i]] = node;
                ans += min(1 + minExitsFrom(G[node][i], true), minExitsFrom(G[node][i], false));
            }
        }
    }
    else{
        ans = 0;
        for(int i = 0; i < G[node].size(); ++i){
            if(G[node][i] != parent[node]){
                parent[G[node][i]] = node;
                ans += 1 + minExitsFrom(G[node][i], true);
            }
        }
        //ans = op1;
    }
    return dp[node][selected] = ans;
}


int main(){
    int n;
    while(cin >> n && n){
        for(int i = 0; i < MAXNODES; ++i){
            parent[i] = -1;
            weight[i] = 1;
            G[i].clear();
        }
        for(int i = 0; i < n; ++i){
            int m; cin >> m;
            //cout<<i+1<<" ";
            for(int j = 0; j < m; ++j){
                int v; cin >> v;
                G[i].push_back(v-1);
                //cout<<(G[i][j]+1)<<" ";
            }
            //cout<<endl;
        
        }
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 2; ++j)
                dp[i][j] = -1;
    
        
        int ans = min (minExitsFrom(0,0), minExitsFrom(0,1)+1);
        cout<<ans<<endl;
    }
    return 0;
}
