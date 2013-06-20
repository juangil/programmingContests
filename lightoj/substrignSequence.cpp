# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <string>
# include <cassert>
using namespace std;

/*void kmpMatcher(const string &s,const string &w){
     int m = w.size();
     vector<int> T(m + 1);
     T[0] = -1;
     for(int i = 1; i < w.size(); ++i){
          T[i+1] = T[i];
          while(w[k + 1] != w[i]) k = T[k];
          if(w[k+1] == w[i]) k++;
          T[k] = k;
     }
     
     int q = -1;
     for(int i = 0; i < s.length(); ++i){
          while(q >= 0 && w[q+1] != s[i]) q = T[q];
          if(w[q + 1] == s[i]) q++;
          if(q == w.size() - 1){//match
               cout<<i - w.size() + 1<<endl;
               q = T[q];
          }
     }
     return;         
}*/

int kmpMatcher(const string &needle, const string &haystack) {
  int cont = 0;
  int m = needle.size();
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and
           needle[border[i+1]] != needle[i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }

  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > -1 and needle[seen] != haystack[i]) {
      seen = border[seen];
    }
    if (++seen == m) {
      cont++;
      seen = border[m];
    }
  }
  return cont;
}

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin >> t;
     for(int i = 0; i < t; ++i){
          string needle;
          string haystack;
          cin >> haystack;
          cin >> needle;
          if(needle.size() > haystack.size()){printf("Case %d: %d\n", i+1, 0);}
          printf("Case %d: %d\n", i+1, kmpMatcher(needle, haystack));
      }
      
      return 0;
}
     
     
