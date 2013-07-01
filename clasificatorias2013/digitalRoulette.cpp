# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <set>

using namespace std;
typedef long long int lli;
typedef vector<int> pol;

lli myPow(lli a, lli b, int n){
     if(b == 0) return 1;
     lli base = a;
     b--;
     while(b--) a = (a*base)%n;
     return a;
}
lli polyn_at(pol p, int &val, int &n)//polynomial calculation with honer's method
{
  lli acum = 0;
  for(int i = 0; i < p.size(); ++i)
     acum = (acum + (p[i]*((myPow(val,i,n)%n)))%n)%n; 
  return acum%n;
}  

int solve(pol &p, int &n, int &m){
     set<int> winners;
     for(int i = 0; i <= m; ++i)
          winners.insert(polyn_at(p, i, n));
     
     return winners.size();
}

int main(){
     int n,m;
     while(cin >> n >> m and ((n + m) != 0)){
          int k;
          cin >> k;
          pol p (k+1);
          for(int i = 0 ; i < k+1; ++i)
               cin >> p[i];
          n += 1;
          cout<<solve(p,n,m)<<endl;
     }
     return 0;
}
