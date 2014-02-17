# include <bits/stdc++.h>


using namespace std;


int N,K;
const int MAXMATCHINGS = (1 << 16);
const int MAXN = 16;

vector<int> tablero(MAXN);
int effort[MAXN];
int gane[MAXN];
int dp[MAXMATCHINGS];

void matching(int bit_mask){
    
    if(dp[bit_mask] != -1) return;
    for(int i = 0; i < N; ++i) gane[i] = 0;
    if(bit_mask != 0){
          int mypoints = 0;
          int total = 0;
          for(int i = 0; i < N; ++i){
               if((bit_mask & (1<<i))){
                  mypoints ++;
                  gane[i] = 1;
                  total += effort[i];
               }
               else gane[i] = 0;
          }
          int mypos;
          for(int k = tablero.size() - 1; k >= 0; --k){
               if(tablero[k] >= mypoints){
                    if(tablero[k] == mypoints){
                         int j = k;
                         while(tablero[j] == mypoints && j >= 0){
                              if(gane[j]){
                                   mypos = j;
                                   j--;
                              }
                              else break;
                         }
                    }
                    else mypos = k - 1;
               }
          }
          if (mypos+1 <= K) dp[bit_mask] = total;
          else dp[bit_mask] = -2;
          return;
    }
    
    double ans = (double)(1<<30);
    for(int i = 0; i < N; ++i)
        if(!(bit_mask & (1 << i)))
               matching(bit_mask | (1 << i));
     
     return;
}


int main(){
     int n,k;
     cin >> n >> k;
     for(int i = 0; i < n; ++i){
          cin >> tablero[i];
          cin >> effort[i];
     }
     
     for(int i = 0; i < (1<<n); ++i)
          dp[i] = -1;
     
     N = n; K = k;
     matching(0);
     int menor = 1<<30;
     for(int i = 0; i < (1<<n); ++i){
          if(dp[i] != -2){
               if(dp[i] < menor)
                    menor = dp[i];
          }
     }
     if(menor == (1 << 30)) cout<<-1<<endl;
     else cout<<menor<<endl;
     return 0;
}