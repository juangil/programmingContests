# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <climits>
# include <cstdio>
# include <cstdlib>
# include <cstring>
using namespace std;

int gcd(int a,int b){
     if(b==0) return a;
     return gcd(b,a%b);
}

typedef long long int lli;



/*lli superGcd(){
    if(myPacks.size() == 0) return 0;
    else if(myPacks.size() == 1) return myPacks[0].first;
    int mygcd = gcd(myPacks[0].first,myPacks[1].first);
    for(int i = 2; i < myPacks.size(); ++i){
        if(i == myPacks.size() - 1) break;
        mygcd = gcd(mygcd, myPacks[i].first);
    }        
    return mygcd;
}

/*int solve (int moneyLeft,int i){
    int mmax = -(1<<30);
    if(i < 0) return 0;
    if(myPacks[i].first > moneyLeft) return solve(moneyLeft, i - 1);
    else
       return mmax = max(solve(moneyLeft, i - 1), solve(moneyLeft - (myPacks[i].first), i - 1) + (myPacks[i].second));
    return mmax;
}*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,n,p,cont = 0;
    while(cin >> c){
          //if(cont > 0) cout<<endl;
          cin >> n >> p;
          vector< pair<int,int> > myShares (n);
          vector< pair<int,int> > myPacks ;
          for(int i = 0; i < n; ++i){
              int a,b;
              cin >> a >> b;
              myShares[i] = (make_pair(a,b));       
          }
          int mygcd = -1;
          //int iii=0;
          
          for(int i = 0; i < p; ++i){
              int k;cin >> k;
              int cost = 0, income = 0; 
              for(int j = 0; j < k; j++){
                  int a,b;
                  cin >> a >> b;
                  cost += myShares[a-1].first*b;
                  income += myShares[a-1].second*b;
              }
              if(income - cost > 0 && cost <= c){
                    myPacks.push_back(make_pair(cost,income-cost));
                if(mygcd == -1)
                    mygcd = cost;
                else if(cost >= 0) mygcd = gcd(mygcd,cost);
              }
          }
          if(gcd == 0){
              cout<<0<<endl;
              continue;
          }
          int newCapital =  c/mygcd;
          for(int i = 0; i < myPacks.size(); ++i){
                myPacks[i].first /= mygcd;
                myPacks[i].second /= mygcd;
          }
          int **dp  = (int **) malloc (2*sizeof(int *));
          dp[0] = (int *) malloc ((newCapital+1)* sizeof(int));
          dp[1] = (int *) malloc ((newCapital+1)* sizeof(int));
          
          dp[0][0] = 0;
          for (int i=0 ; i<=newCapital ; i++)
              dp[0][i] = 0;
	     
//          memset(dp, 0, sizeof(2*(newCapital+1)*sizeof(int)));
          bool flag = true;
          int curr, prev;
          
          for(int i = 0; i < myPacks.size(); ++i){
               curr = (flag)?1:0;
               prev = (flag)?0:1;
               for(int j = 0; j <= newCapital; ++j){
                    if(myPacks[i].first > j)
                         dp[curr][j] = dp[prev][j];
                    else
                         dp[curr][j] = max(dp[prev][j], myPacks[i].second + dp[prev][j - myPacks[i].first]);
               }
               flag = !flag;
          }
          cout<<dp[(flag)?0:1][newCapital]*mygcd<<endl;
          //cont++;
    }
    return 0;
}

          
