# include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G;
int ans = 0;
int M;

void dfs(int ini, vector<int> &have_cat){
    vector<int> visited(G.size(), 0);
    vector< pair<int, int> > acum(G.size());
    acum[0].first = have_cat[0];
    acum[0].second = have_cat[0];
    stack<int> Q;
    Q.push(ini);
    while(!Q.empty()){
        int current = Q.top();
        Q.pop();
        visited[current] = 1;
        //cout << acum[current].first << " " << acum[current].second << " "  << G[current].size() << endl;
        //cout << current << endl;
        if(G[current].size() == 1 && current != 0){
            if(acum[current].second <= M)
                ans++;
        }
        for(int i = 0; i < G[current].size(); ++i){
            if(!visited[G[current][i]]){
                Q.push(G[current][i]);
                if(have_cat[G[current][i]] == 1){ //&& have_cat[current] == 1){
                    acum[G[current][i]].first = acum[current].first + 1;
                    acum[G[current][i]].second = max(acum[current].second, acum[G[current][i]].first);
                }
                else if(have_cat[G[current][i]] == 0){
                    acum[G[current][i]].first = 0;
                    acum[G[current][i]].second = acum[current].second;
                }
            }
        }
    }
    return;
}



int main(){
    int m, n;
    cin >> n >> m;
    M = m;
    vector<int> have_cat(n);
    G.clear();
    G.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> have_cat[i];
    for(int i = 0; i < n - 1; ++i){
        int a,b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
        //cout << "paso" << endl;
    }
    //cout << endl;
    dfs(0, have_cat);
    cout << ans << endl;
}
