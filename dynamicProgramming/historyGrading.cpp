# include <bits/stdc++.h>

using namespace std;
const int MAXN = 22; 
int dp [MAXN];
int my_pos[MAXN];
int new_pos[MAXN];
int N;
int lis(int i){
    if(dp[i] != -1) return dp[i];
    if(i == 0) return 1;
    int ans = 1;
    for(int j = 0; j < i; ++j){
        if((new_pos[i] > new_pos[j]) && (my_pos[i] > my_pos[j]))
            ans = max(ans, 1 + lis(j));
        else if((new_pos[i] < new_pos[j]) && (my_pos[i] < my_pos[j]))
            ans = max(ans, 1 + lis(j));
    }
    //cout<<ans<<endl;
    return ans;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> my_pos[i];
    N = n;
    n--;
    while(cin >> new_pos[0]){
        for(int i = 1; i < N; ++i)
            cin >> new_pos[i];
        
        for(int i = 0; i < N; ++i) dp[i] = -1;
        
        int ans = 1;
        for(int i = 0; i < N; ++i){
            dp[i] = lis(i);
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }

}
