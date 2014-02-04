# include <bits/stdc++.h>
# define MAXLEN 1000
using namespace std;

int myInts[MAXLEN];
int dp[MAXLEN];

int lis(int i){
     if(dp[i] != -1) return dp[i];
     if(i == 0) return 1;
     int ans = 1;
     for(int j = 0; j < i; ++j){
          if(myInts[i] > myInts[j]){
               ans = max(ans, 1 + lis(j));
          }
     }
     return ans;
}


int main(){
     int n;
     while(cin >> n){
          
          for(int i = 0; i < n; ++i){
               cin >> myInts[i];
               dp[i] = -1;
          }
          
          int ans = 1;
          for(int i = 0; i < n; i++){
               dp[i] = lis(i);
               ans = max(ans, dp[i]);
          }
          cout<<ans<<endl;
     }
     return 0;
}
