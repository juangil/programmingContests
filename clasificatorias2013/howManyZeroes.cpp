# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <cassert>
# include <string>
# include <vector>
# include <cstring>
# include <sstream>
using namespace std;

typedef long long int lli;

template<class T> string toStr(T a){stringstream ss; ss << a; return ss.str();}

lli dp[35][35][2][2];

lli solve(int index,lli zeroes, int tope, int leading, string &myNum){
     if(index == myNum.size()) return (!leading)? zeroes : 0;
     if(dp[index][zeroes][tope][leading] != -1) return dp[index][zeroes][tope][leading];
     int mmax = (tope)? myNum[index]-'0':9;
     lli ans = 0;
     for(int i = 0; i <= mmax; ++i)
          ans += solve(index + 1, zeroes + (i == 0 and !leading), ((i == mmax) and tope), ((i == 0) and leading), myNum);
          
     return dp[index][zeroes][tope][leading] = ans;
}


int main(){
     lli m,n;
     while(cin >> m >> n and m != -1 and n != -1){
          if(m + n == 0){
               cout<<1<<endl;
               continue;
          }
          memset(dp, -1, sizeof(dp));
          string tmp = toStr(m - 1);
          lli zeroesa = (m == 0)? -1:solve(0,0,1,1,tmp);
          memset(dp, -1, sizeof(dp));
          tmp = toStr(n);
          lli zeroesb = (n == 0)? -1:solve(0,0,1,1,tmp);
          cout<<zeroesb - zeroesa<<endl;
     }
     return 0;
}

          
