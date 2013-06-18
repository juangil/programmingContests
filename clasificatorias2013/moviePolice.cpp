using namespace std;
#include<iostream>
#include<string>
#include<cassert>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#define FR(i,n) for(int i = 0 ; i<(n) ; ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define init(x) memset(x, 0, sizeof(x))
template<class T>
int to_int(T r){stringstream ss; ss<<r; int k; ss>>k; return k;}

int main(){
      int m,n;
      cin >> m >> n;
      vector<string> myMovies (m);
      FR(i,m) cin >> myMovies[i];
      FR(i,n){
         string q;
         cin >> q;
         int mmenor = 1 << 30;
         int idmenor = -1;
         FR(j,myMovies.size()){
            if(myMovies[j].size() < q.size()) continue;
            int menor = 1<<30;
            int hamming = 0;
            FR(k, myMovies[j].length()){
               if(k + (q.size() - 1) <= myMovies[j].size() - 1){
                  int contq = 0;
                  hamming = 0;
                  for(int h = k; h <= k + (q.size() - 1); h++){
                      if(myMovies[j][h] != q[contq]) hamming += 1;
                      contq += 1;
                  }
                  if(hamming < menor)
                     menor = hamming;
               }
               else break;
            }
            if(menor < mmenor){
               mmenor = menor;
               idmenor = j+1;
            }
         }
         cout<<idmenor<<endl;  
      }
    return 0;
}
