# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main(){
     int n;
     while(cin >> n && n != 0){
          string h; cin >> h;
          bool flag1 = false, flag2 = false;
          int cont = 0, mayor = (1<<30);
          for(int i = 0; i < h.size(); ++i){
               if(h[i] == 'R'){
                    flag1 = true;
                    cont = i;
               }
               if((h[i] == 'Z') && flag1){
                    cont = 0;
                    mayor = 0;
                    flag2 = true;
                    break;
               }
               if(h[i] == 'D' && flag1){
                    int size = i - cont;
                    flag2 = true;
                    if(size < mayor) mayor = size;
               }
           }
           int mmayor = (!flag1 || !flag2)? 0:mayor;
           //cout<<mmayor<<endl;
           flag1 = false; flag2 = false; cont = 0; mayor = (1<<30);
           for(int i = 0; i < h.size(); ++i){
               if(h[i] == 'D'){
                    flag1 = true;
                    cont = i;
               }
               if((h[i] == 'Z') && flag1){
                    cont = 0;
                    mayor = 0;
                    flag2 = true;
                    break;
               }
               if(h[i] == 'R' && flag1){
                    int size = i - cont;
                    flag2 = true;
                    if(size < mayor) mayor = size;
               }
           }
           int mmayor2 = (!flag1 || !flag2)? 0:mayor;
           if(mmayor2 == 0) cout<<mmayor<<endl;
           else if(mmayor == 0) cout<<mmayor2<<endl;
           else if(mmayor2 < mmayor) cout<<mmayor2<<endl;
           else cout<<mmayor<<endl;
      }
      return 0;
 }
