# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <cstring>
# include <algorithm>

using namespace std;

int trips [111];
int shits [111];
int dp [111][111];
int n;

int solve(int currentTrip, int currentShit){//this function gives me the best solution
     if(currentShit > n) currentShit = n;
     if(currentTrip == n) return 0;
     if(dp[currentTrip][currentShit] != -1) return dp[currentTrip][currentShit];
     int a = trips[currentTrip] + solve(currentTrip + 1, shits[currentTrip] + currentShit);//what happens if i choose not to consume a shit for trip i
     int b = 1<<30;
     if(currentShit){
          b =(trips[currentTrip]>>1) + solve(currentTrip + 1, shits[currentTrip] + currentShit - 1);//what happens if i choose to consume a piece of shit for trip j
     }
     return dp[currentTrip][currentShit] = min(a,b);
} 
          

int main(){
     while(cin >> n and n){
          for(int i = 0; i < n; ++i)
               cin >> trips[i] >> shits[i];
          memset(dp, -1, sizeof(dp));
          cout<<solve(0,0)<<endl;
     }
     return 0;
}
     
