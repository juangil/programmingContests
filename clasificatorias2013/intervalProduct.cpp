# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <algorithm>

using namespace std;

class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    if(from == 0) return query(to);
    return query(to) - query(from-1);
  }

};

int main(){
     int n,k;
     while(cin >> n >> k){
          FenwickTree minus(n);
          FenwickTree zeroes(n);
          for(int i = 0; i < n; ++i){
               int num;
               cin >> num;
               if(num == 0){
                    zeroes.add(i,1);
                    minus.add(i,0);
               }
               else if(num < 0){
                    minus.add(i,1);
                    zeroes.add(i,0);
               }
               else{
                    minus.add(i,0);
                    zeroes.add(i,0);
               }
          }
          //for(int i = 0; i < n; ++i) cout<<minus.query(i)<<endl;
          for(int i = 0; i < k; ++i){
               char op;
               int a,b;
               cin >> op >> a >> b;
               if(op == 'C'){
                    if(b == 0){
                         if(zeroes.query(a - 1) == zeroes.query(a - 2)){
                               zeroes.add(a - 1,1);
                               if(minus.query(a - 1) != minus.query(a - 2))minus.add(a - 1, -1);
                         }
                    }
                    else if(b < 0){
                         if(minus.query(a - 1) == minus.query(a - 2)){
                               minus.add(a - 1,1);
                               if(zeroes.query(a - 1) != zeroes.query(a - 2))zeroes.add(a - 1, -1);
                         }
                    }
                    else{
                         if(minus.query(a - 1) != minus.query(a - 2))
                               minus.add(a - 1, -1);
                         else if(zeroes.query(a - 1) != zeroes.query(a - 2))
                               zeroes.add(a - 1, -1);
                    } 
               }
               else{
                    if(a - 1 == b - 1){
                         if(zeroes.query(a - 1) == zeroes.query(a - 2)){
                              if(minus.query(a - 1) == minus.query(a - 2)) cout<<"+";
                              else cout<<"-";
                         }
                         else cout<<0;
                    }
                    else{
                         if(zeroes.query(a -1, b - 1) == 0){
                              if(minus.query(a - 1, b - 1)%2 == 0)cout<<"+";
                              else cout<<"-";
                         }
                         else cout<<0;
                    }
               }
          }
          cout<<endl;
     }
     return 0;
}             

