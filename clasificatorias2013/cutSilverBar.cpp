# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <algorithm>

using namespace std;

int myf(int n){
          int cont = 0;
          while(n--){cont++; n/=2}
          return cont;
}

int main(){
     int n;
     while(cin >> n and n){
          cout<<myf(n) - 1<<endl
     }
     return 0;
}
