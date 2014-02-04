# include <bits/stdc++.h>

using namespace std;

int main(){
     int t,cont = 0;
     cin >> t;
     while(t--){
          string cad;
          cin >> cad;
          bool mio = false;
          if(cad.size() < 3){
               printf("Bad\n");
               continue;
          }
          for(int i = 0; i < cad.size()-2; ++i){
               if((cad[i] == '0' && cad[i + 1] == '1' && cad[i+2] == '0')||(cad[i] == '1' && cad[i + 1] == '0' && cad[i+2] == '1')){
                    mio = true;
                    break;
               }
          }
          if(mio) printf("Good\n");
          else printf("Bad\n");
     }
     return 0;
}
