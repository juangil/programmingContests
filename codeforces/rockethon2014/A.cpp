# include <bits/stdc++.h>

using namespace std;

int main(){
     string mio;
     cin >> mio;
     vector<string> myProt;
     string lleve = "";
     for(int i = 0; i < mio.size(); ++i){
          char tmp = mio[i];
          if(mio[i+1] != tmp){
               lleve = lleve + tmp;
               myProt.push_back(lleve);
               lleve = "";
          }
          else lleve = lleve + tmp;
     }
          
     int cont = 0;
     for(int i = 0; i < myProt.size(); ++i)
          if(myProt[i].size()%2 == 0)cont++;
     
     cout<<cont<<endl;

     return 0;
}