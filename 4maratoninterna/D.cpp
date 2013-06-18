# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# define FR(i,n) for(int i = 0; i < (n); ++i)
# define fr(i,j,n) for(int i = j; j < n; ++i)
# define forDown(i,j) for(int i = j; i >= 0; i--)
using namespace std;

bool isGrow(char a, string target)
{
   FR(i, target.size()) if(target[i] == a) return true;
   return false;
}
   
   
   

int main()
{
   int a,b;
   while(cin >> a >> b and (a+b))
   {
      //cout<<a<<" -  "<<b<<endl;
      string target;
      cin >> target;
      char field [a][b];
      FR(i,a)
        scanf("%s", &field[i]);
      int area = 0;
      bool flag2 = false;     
      forDown(i,a){
        forDown(j,b){
          //cout<<i<<" "<<j<<endl;
          FR(k,a){
            FR(m,b){
              set<char> mySet;
              if(k + i > a || m + j > b) continue;
              fr(l,k,k+i){
                bool flag = false;
                fr(o,m,m+j){
                  if(!isGrow(field[l][o], target)){
                    flag = true;
                    break;
                  }
                  else mySet.insert(field[l][o]);               
                }
                if(flag) break;
                else continue;
              }
              if(mySet.size() == target.length()){
                 area = i*j;
                 flag2 = true;
                 break;
             }
            }
            if(flag2) break;
          }
          if(flag2) break;
        }
        if(flag2) break;
     }
     cout<<area<<endl;
   }
   return 0;
}
                 
                
              
                   
            
        
        
      
      
         
