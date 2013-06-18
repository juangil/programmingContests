# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <cstring>
# include <sstream>
# define FR(i,n) for(int i = 0; i < n; ++i)
using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

bool repeated(int i){
    string s = toStr(i);
    FR(i,s.length()){
      FR(j,s.length()){
          if(i != j){
             if(s[i] == s[j]) return true;
          }
      }
    }
    return false;
}

int main(){
   int n,m, cont=0;
   //cout<<"paso"<<endl;
   while(scanf("%d %d", &n, &m) != EOF){
      //cout<<n<<m<<endl;
      cont =0;
      for(int i = n ; i <= m; ++i){
          if(!repeated(i)) cont +=  1;
      }
      cout<<cont<<endl;
   }
   return 0;
}
