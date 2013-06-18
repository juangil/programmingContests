using namespace std;
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <cstring>
# define FR(i,n) for(int i = 0; i < n; ++i)

int price[22][22];
int dp [22][(20*200) + 4];

int shop(int moneyLeft, int garmentId, int lastGarment, vector<int> &models, int &M){
     if(moneyLeft < 0) return -(1<<30);
     if(garmentId == lastGarment) return M - moneyLeft;
     if(dp[garmentId][moneyLeft] != -1) return dp[garmentId][moneyLeft];
     int mmax = -(1<<30);
     FR(i,models[garmentId])
          mmax = max(shop(moneyLeft - price[garmentId][i], garmentId+1, lastGarment, models, M),mmax);
     return dp[garmentId][moneyLeft] = mmax;     
}

int main(){
     int n,m,c,k;
     cin >> n;  
     FR(i,n){
       memset(price,-1,sizeof (price));
       memset(dp,-1,sizeof (dp));
       cin >> m >> c;
       vector<int> models(c);
       FR(j,c){
          cin >> k;
          models[j] = k;
          FR(h,k)
               cin >> price[j][h];
       }
       int moneyLeft = m;
       int max = shop(moneyLeft, 0, c, models, m); 
       if(max < 0) cout<<"no solution"<<endl;
       else cout<<max<<endl;
     }
     return 0;
}
               
       

