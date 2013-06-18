# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <queue>
# include <vector>
# include <string>
# include <sstream>
# include <algorithm>
# include <map>
# include <set>
# define FR(i,n) for(int i = 0; i < n ; ++i)

using namespace std;

typedef vector<string> vs;

vs nextPerm(string temp)
{ 
    vs children;
    string a = temp;
    FR(i,8)
    {
       a = temp;
       if(temp[i] == 'A')
       {
          if(i+1 <= 7 && temp[i+1] == '.')          
          {
               a[i] = '.';
               a[i+1] = 'A';
               children.push_back(a);
               //cout<<a<<endl;
          }
          a = temp;
          if(i+2 <= 7 && temp[i+1] != '.' && temp[i+2] == '.')
          {  
               a[i] = '.';
               a[i+2] = 'A';
               children.push_back(a);
               //cout<<a<<endl;
          }
       }
       else if(temp[i] == 'V')
       {
          if(i-1 >= 0 && temp[i-1] == '.')
          {
               a[i] = '.';
               a[i-1] = 'V';
               children.push_back(a);
               //cout<<a<<endl;
          }
          a = temp;
          if(i-2 >= 0 && temp[i-2] == '.' && temp[i-1] != '.')
          {  
               a[i] = '.';
               a[i-2] = 'V';
               children.push_back(a);
               //cout<<a<<endl;
          }        
       }
       else if(temp[i] == 'R')
       {
          if(i-1 >= 0 && temp[i-1] == '.')
          {
               a[i] = '.';
               a[i-1] = 'R';
               children.push_back(a);
               //cout<<a<<endl;
          }
          a = temp;
          if(i-2 >= 0 && temp[i-2] == '.' && temp[i-1] != '.')
          {  
               a[i] = '.';
               a[i-2] = 'R';
               children.push_back(a);
               //cout<<a<<endl;
          }
          a = temp;
          if(i+1 <= 7 && temp[i+1] == '.')          
          {
               a[i] = '.';
               a[i+1] = 'R';
               children.push_back(a);
               //cout<<a<<endl;
          }
          a = temp;
          if(i+2 <= 7 && temp[i+2] == '.' && temp[i+1] != '.')
          {  
               a[i] = '.';
               a[i+2] = 'R';
               children.push_back(a);
               //cout<<a<<endl;
          }
       } 
     }
     return children;
}
      
int bfsCost(string ini, string target)
{
    
   map<string, int> visit; // el dfs es exactamente lo mismo
   queue< pair<string,int> > Q; //dfs: solo que se define un stack en vez de un queue
   Q.push(make_pair(ini, 0));
   //int ans = 0;
   while(!Q.empty())
   {
      pair<string,int> actual = Q.front();//dfs: de la pila se saca del ultimo que meti LIFO stack.pop
      Q.pop();
      if(visit[actual.first])continue;
      visit[actual.first] = 1;
      if (actual.first == target) return actual.second;     
      vs children = nextPerm(actual.first);
      /*cout<<"papasito: "<<actual.first<<endl;
      cout<<endl;
      for(int i = 0; i < children.size(); i++) cout<<children[i]<<" level : "<<actual.second+1<<endl;
      cout<<endl;*/
      FR(i,children.size())
              Q.push(make_pair(children[i], actual.second + 1));//tambien se hace push.
   }
   return -1;
}
int main()
{
   int n;
   cin >> n;
   FR(i,n)
   {
      string ini, target;
      cin >> ini;
      cin >> target;
      int steps =  bfsCost(ini, target);
      if(steps >= 0) cout<<"Caso "<<i+1<<": "<<steps<<endl;
      else cout<<"Caso "<<i+1<<": imposible"<<endl;
   }
   return 0;
}
      
      

