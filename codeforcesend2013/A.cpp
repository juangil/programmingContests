
# include <bits/stdc++.h>
using namespace std;


int main(){
     int a, b;
     
     while(cin >> a >> b){
          int ans = a;
          int tmp = 0;
          while(a >= b){
               tmp = a%b;
               a /= b;
               ans += a;
               a += tmp;
               //cout<<a<<endl;

          }
          cout<<ans<<endl;
     }
     return 0;
     
}
