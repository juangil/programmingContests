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

typedef long long int lli;

lli gcd(lli a,lli b){
     if(b==0) return a;
     return gcd(b,a%b);
}


vector< pair<lli,lli> > myPacks;
lli* dp1; lli* dp2;

lli solve (lli moneyLeft,int i){
    lli mmax = -(1<<30);
    if(i < 0) return 0;
    if(myPacks[i].first > moneyLeft) return solve(moneyLeft, i - 1);
    else
       return mmax = max(solve(moneyLeft, i - 1), solve(moneyLeft - (myPacks[i].first), i - 1) + (myPacks[i].second));
    return mmax;
}

int main(){
    lli c,cont = 0;
    int n = 0;
    int p = 0;
    while(scanf("%lld", &c) != EOF){
          if(cont > 0) cout<<endl;
          cin >> n >> p;
          vector< pair<lli,lli> > myShares (n);
          myPacks.clear();
          for(int i = 0; i < n; ++i){
              lli a,b;
              cin >> a >> b;
              myShares[i] = (make_pair(a,b));       
          }//cout<<"hey1"<<endl;
          
          lli superGcd = -1;
          for(int i = 0; i < p; ++i){
              int k;cin >> k;
              lli cost = 0, income = 0; 
              for(int j = 0; j < k; j++){
                  int a,b;
                  cin >> a >> b;
                  cost += myShares[a-1].first*b;
                  income += myShares[a-1].second*b;
              }
              lli mm = 0;
              if(income <= cost || cost > c)
                  continue;
              cout<<cost<<" "<<income-cost<<" "<<(income <= cost)<<endl;
              myPacks.push_back(make_pair(cost,income-cost));
              if(superGcd == -1)
                  superGcd = cost;
              else{
                  if(cost >= 0)
                      superGcd = gcd(superGcd, cost);
              }
              
          }
          
          if(myPacks.size() == 0)cout<<0<<endl;
          lli wMax =  c/superGcd;
          cout<<wMax<<endl;
          dp1 = (lli*) calloc(wMax + 2, sizeof(lli));
          dp2 = (lli*) calloc(wMax + 2, sizeof(lli));
          cout<<dp1[0]<<endl;
          for(int i = 0; i < myPacks.size(); ++i){
                myPacks[i].first /= superGcd;
                myPacks[i].second /= superGcd;
          }
          cout<<solve(wMax,myPacks.size()-1)*superGcd<<endl;
          cont++;
    }
    return 0;
}

          
