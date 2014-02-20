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
    if(bit_mask >= 0){
          vector<int> nuevo_tablero = tablero;
          int mypoints = 0;
          int total = 0;
          for(int i = 0; i < N; ++i){
               if((bit_mask & (1<<i))){
                  mypoints ++;
                  gane[i] = 1;
                  total += effort[i];
               }
               else{
                  gane[i] = 0;
                  nuevo_tablero[i] += 1;
               }
          }
          //for(int i = 0; i < N; ++i) cout<<nuevo_tablero[i]<<" gane "<<gane[i]<<" ,";
          //cout<<endl;
          int mypos = N + 1;
          for(int i = 0; i < N; ++i){
                if(mypoints > nuevo_tablero[i]) mypos--;
                else if(mypoints == nuevo_tablero[i] && gane[i]) mypos--;
          
          }
          //cout<<mypos<<" "<<total<<" "<<mypoints<<endl;
          if(mypos <= K) dp[bit_mask] = total;
          else dp[bit_mask] = -2;
    }
    
    for(int i = 0; i < N; ++i){
        if(!(bit_mask & (1 << i)))
               matching(bit_mask | (1 << i));
    }
     
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
     
     //dp[0] = -2;
     N = n; K = k;
     matching(0);
     int menor = 1<<30;
     for(int i = 0; i < (1<<n); ++i){
          //cout<<dp[i]<<endl;
          if(dp[i] != -2 && dp[i] != -1){
               if(dp[i] < menor)
                    menor = dp[i];
          }
     }
     if(menor == (1 << 30)) cout<<-1<<endl;
     else cout<<menor<<endl;
     return 0;
}
