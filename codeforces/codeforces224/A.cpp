# include <bits/stdc++.h>

using namespace std;

int main(){
     string mio;
     cin >> mio;
     string lleve;
     cin >> lleve;
     int faltan = lleve.size();
     int contleft = 0, contright = 0;
     for(int i = 0; i < mio.size(); ++i){
          if(mio[i] == '|') left = false;
          contleft +=(left)? 1:0;
          contright += (!left)? 1:0; 
     }
     string left;
     string right;
     if(contleft > contright){
          int dif = contleft - contright;
          if(dif <= faltan){
               faltan -= dif;
               contleft += dif;
               
          }
          else paila = true;
     }
     else if(contleft < contright){
          int dif = contright - contleft;
          if(dif <= faltan){
               faltan -= dif;
               contright += dif;
          }
          else paila = true;
     }
     if(paila) cout<<"Impossible"<<endl;
     else if(contleft == contright){
          if(faltan%2 == 0)
     }

}
