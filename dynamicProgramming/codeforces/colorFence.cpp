# include <bits/stdc++.h>

using namespace std;

int main(){
     int v;
     int paint [9];
     while(cin >> v){
          int mincant = (1<<30);
          int mindig = -1;
          for(int i = 0; i < 9; ++i){
               cin >> paint[i];
               if(paint[i] <= mincant){
                    mincant = paint[i];
                    mindig = i;
               }
          }
          //cout<<mindig<<endl;
          if(mincant > v){
               cout<<-1<<endl;
               continue;
          }
          int total = v;
          int canput = v/mincant;
          int used = canput*mincant; 
          string ans = "";
          //cout<<canput<<" "<<used<<" "<<total<<endl;
          for(int i = 8; i >= 0; i--){
            //   cout<<i<<" "<<total - paint[i]<<" "<<used - paint[mindig]<<endl;
               while((total - paint[i] >= used - paint[mindig]) && canput > 0){
                    total -= paint[i];
                    used -= paint[mindig];
                    ans.push_back((char)('0' + i + 1));
                    canput--;
               }
          }
          
          cout<<ans<<endl;
     }
     
     
     return 0;
}
