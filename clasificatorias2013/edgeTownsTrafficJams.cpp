# include <cstdio>
# include <vector>
# include <cmath>
# include <algorithm>
# include <cstdlib>
# include <iostream>
# include <sstream>

using namespace std;

template<class T> int to_int(T t){ stringstream ss; ss<<t; int r; ss>>r; return r; }
template<class T> string to_str(T t){ stringstream ss; ss<<t; return ss.str(); }
typedef unsigned long long ulli;

const int MAXNODES = 111;

ulli oldG[MAXNODES][MAXNODES];
ulli newG[MAXNODES][MAXNODES];
int n;

void floydWarshall(){
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < n; ++j){
               for(int k = 0; k < n; ++k){
                    oldG[j][k] = min(oldG[j][k], oldG[j][i] + oldG[i][k]);
                    newG[j][k] = min(newG[j][k], newG[j][i] + newG[i][k]);
               }
          }
     }
}

int main(){
     string buffer;
     while(getline(cin,buffer)){
          n = to_int(buffer);
          if(n == 0) break;
          
          for(int i = 0; i < MAXNODES; ++i){
               for(int j = 0; j < MAXNODES; ++j){
                    oldG[i][j] = (1<<30);
                    newG[i][j] = (1<<30);
               }
          }
          for(int i = 0; i< n; ++i){
               getline(cin,buffer);
               stringstream ss(buffer);
               ss>>buffer;
               int u = to_int(buffer);
               while(ss>>buffer){
                   int v = to_int(buffer);
                   oldG[u-1][v-1] = 1;
               }
          }
          for(int i = 0; i< n; ++i){
               getline(cin,buffer);
               stringstream ss(buffer);
               ss>>buffer;
               int u = to_int(buffer);
               while(ss>>buffer){
                   int v = to_int(buffer);
                   newG[u-1][v-1] = 1;
               }
          }
          getline(cin,buffer);
          stringstream ss(buffer);
          int a; ss>>a;
          int b; ss>>b;
          
          floydWarshall();//we run floydWarshall over the two GRAPHs in order to find the minimun distance between any pair of vertex or itnersections
          
          int flag = 0;
          for(int i = 0; i <= n and !flag; ++i){
               for(int j = 0; j <= n and !flag; ++j){
                    if(i == j or oldG[i][j] == (1<<30)) continue;
                    if(newG[i][j] > ((oldG[i][j]*a) + b)) flag = 1;
               }
          }
          if(flag) cout<<"No"<<endl;
          else cout<<"Yes"<<endl;    
     }
     return 0;
}
