# include <bits/stdc++.h>

using namespace std;

const int MAXNODES = 1002;

vector< vector<int> > G(MAXNODES);
int dp[MAXNODES][MAXNODES][2];


int f(int node, int p, int b) {
    
    int &ans = dp[node][p][b];
    if (ans != -1) return ans; 
    if (b) {
        ans = 0;
        for (int i = 0; i < G[node].size(); ++i) {
            if (G[node][i] == p) continue;
            ans += min( f(G[node][i], node, 1) + 1, f(G[node][i], node, 0));
        }
    } else {
        ans = 0;
        for (int i = 0; i < G[node].size(); ++i) {
            if (G[node][i] == p) continue;
            ans += f(G[node][i], node, 1) + 1;
        }
    }
    //cout<<ans<<endl;
    return  ans;
    
}


int main(){
    int n;
    while(cin >> n && n){
        for(int i = 0; i < MAXNODES; ++i){
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
        
        for (int i = 0; i <= n; ++i)
            for (int k = 0; k <= n; ++k)
                for (int j = 0; j < 2; ++j)
                    dp[i][k][j] = -1;
    
                    
        int ans = min (f(0,0,0), f(0,0,1)+1);
        cout<<ans<<endl;    
        
        
    }
    return 0;
}
