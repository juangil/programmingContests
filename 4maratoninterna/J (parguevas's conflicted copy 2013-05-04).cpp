# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <iostream>
# include <algorithm>
# include <cstring>
# define FR(i,n) for(int i = 0; i < n; i++)


using namespace std;

int dp [1<<16];
vector<int> colors;
int totalColors = 0;

double solve (int state, int turn = 0)
{
   if(dp[state] != -1) return dp[state];
   double expected = 0.0;
   FR(i,colors.size())
   {
      if(state & 1<<i)
         expected += ((colors[i] - 2)/(totalColors - __builtint_pop_count(state)))*turn;
      else
         expected += solve(state | 1<<i, turn+1)*((colors[i] - 1)/(totalColors - __builtint_pop_count(state)));
   }
   return dp[state] = expected;
}

int main()
{
   int t;
   cin >> t;
   FR(i,t)
   {
     int k;
     cin >> k;
     colors = vector<int> (k);
     totalColors = 0;
     FR(j,k)
     {
       cin>>colors[i];
       totalColors += colors[i];
     }
     memset(dp,-1,sizeof(dp));
     cout<<"Caso "<<i+1<<": "<<solve(0)<<endl;
   }
   return 0;
}
     
     
     
     
