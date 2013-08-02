# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <map>
# include <vector>

using namespace std;

#define foreach(it,x) for(typeof((x).begin()) it  = (x).begin(); it != (x).end(); ++it)

int main(){
     int a,b,c,d;
     while(cin >> a >> b >> c >> d and (a+b+c+d)){
          map<string,string> mutations;
          map<string, int> ini;
          map<string, int> tar;
          map<string, int> visited;
          int indeterministic = 0;
          //cout<<a<<b<<c<<d<<endl;
          for(int i = 0; i < a; ++i){
               string ori; string dest;
               cin >> ori >> dest;
               if(visited[ori]){
                    if(mutations[ori] != dest)
                         indeterministic = 1;
                    continue;
               }
               mutations[ori] = dest;
               visited[ori] = 1;
          }
          for(int i = 0; i < b; ++i){
               string ori; int times;
               cin >> ori >> times;
               ini[ori] += times;
          }
          for(int i = 0; i < c; ++i){
               string ori; int times;
               cin >> ori >> times;
               tar[ori] += times;
          }    
          if(indeterministic){
               cout<<"Protein mutations are not deterministic"<<endl;
               continue;
          }
          int npasos = -1;
          for(int i = 0; i <= d; ++i){
               std::map<string, int>::iterator it1 = ini.begin();
               std::map<string, int>::iterator it2 = tar.begin();

               for(it1 = ini.begin(), it2 = tar.begin(); it1 != ini.end() and it2 != tar.end(); ++it1, ++it2){
               //while(it1 != ini.end() and it2 != tar.end()){	
                    if(it1->first != it2->first or it1->second != it2->second)break;
               }
               if(it1 == ini.end() and it2 == tar.end()){
                    npasos = i;
                    break;
               }
               map<string, int> tmp;
               foreach(it,ini){
                    if(mutations.count(it->first) > 0)//it's because there is an entry in the mutations with p = it->first
                         tmp[mutations[it->first]] += it->second;
                    else
                         tmp[it->first] += it->second;
               }
               ini = tmp;
          }
          if(npasos >= 0) cout<<"Cure found in "<<npasos<<" mutation(s)"<<endl;
          else cout<<"Nostalgia for Infinity is doomed"<<endl;
     }
     return 0;
}
               
                         
                    
                    
                              
               
               
               
               
               
               
               
               
               
               
               
               
               
               
