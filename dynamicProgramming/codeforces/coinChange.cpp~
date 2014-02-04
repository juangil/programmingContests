# include <bits/stdc++.h>
# define MAXLEN 1000 
using namespace std;

const int infin = (1<<30);
int dp [MAXLEN];
int myCoins [MAXLEN];
int N;

int solve(int amount){
     if(amount < 0) return infin;
     if(dp[amount] != -1)return dp[amount];
     int minCoin = infin;
     cout<<amount<<endl;
     for(int i = 0; i < N; ++i){
          cout<<amount - myCoins[i]<<" ";
          int ans = solve(amount - myCoins[i]);
          cout<<ans<<endl;
          if(ans < minCoin){
               dp[amount] = 1 + ans;
               minCoin = dp[amount];
          }
     }
     cout<<endl;
     //return dp[amount];
}


int main(){
     int v,n;
     while(cin >> v >> n){
          dp[0] = 0;
          for(int i = 1; i <= v; ++i)
               dp[i] = -1;
          for(int i = 0; i < n; ++i)
               cin >> myCoins[i];
          
          if(v <= 0){
               cout<<0<<endl;
               continue;
          }
          N = n;
          for(int i = 1; i <= v; i++)
               solve(i);
          for(int i = 1; i <= v; i++)
               cout<<dp[i]<<" ";
          cout<<endl;
          cout<<dp[v]<<endl;
     }
     
     return 0;
}
