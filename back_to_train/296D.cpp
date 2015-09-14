# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
lli cost[533][533];
lli mcost[533][533];
int query[533];
lli sumtot[533];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> cost[i][j];

    for(int i = 0; i < n; ++i){
        cin >> query[i];
        query[i]--;
        sumtot[i] = 0;
    }
    for(int k = n - 1; k >= 0; --k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                //cout << cost[i][j] << " " << cost[i][query[k]] + cost[query[k]][j] << endl;
                cost[i][j] = min(cost[i][j], cost[i][query[k]] + cost[query[k]][j]);
            }
        }

        for(int i = k; i < n; ++i){
            for(int j = k; j < n; ++j){
                //cout << cost[query[i]][query[j]] << endl;
                sumtot[k] += cost[query[i]][query[j]];
            }
        }
    }
    for(int i = 0; i < n - 1; ++i)
        cout << sumtot[i] << " ";
    cout << sumtot[n - 1] << endl;
    return 0;
}
