# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <iostream>
# include <algorithm>
# include <cstring>
# define FR(i,n) for(int i = 0; i < n; i++)


using namespace std;

double dp [1<<16];
vector<int> colors;
int totalColors;

double solve (int state, int turn = 0)
{
   if(dp[state] != -1) return dp[state];
   double expected = 0.0;
   FR(i,colors.size())
   {
      if(state & 1<<i)
         expected += ((colors[i] - 1)/(double)(totalColors - __builtin_popcount(state)))*(turn+1);
      else
         expected += ((colors[i])/(double)(totalColors - __builtin_popcount(state)))*solve(state | (1<<i), turn+1);
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
       cin>>colors[j];
       totalColors += colors[j];
     }
     FR(j,1<<16)dp[j]=-1;
     printf("Caso %d: %.3lf\n",(i+1),solve(0));

   }
   return 0;
}
     
     
     
     
