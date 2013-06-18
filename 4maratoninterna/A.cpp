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
# include <cstring>
# include <stack>
# define FR(i,n) for(int i = 0; i < n ; ++i)

using namespace std;

typedef vector<string> vs;
typedef vector< pair<int,int> > vp;
typedef vector<int> vi;
typedef vector<vi>  vii;

vp bfsCost(int ini,vp &sections, vii &G)
{
   int visited [sections.size()]; // el dfs es exactamente lo mismo
   memset(visited, 0, sizeof(visited));
   vp D (sections.size());
   stack< int > Q; //dfs: solo que se define un stack en vez de un queue
   Q.push(ini);
   visited[ini] = 1;
   int mayor = -1;
   int menor = 100000000;
   bool flag = false;
   
   while(!Q.empty())
   {
      int actual = Q.top();
      if(G[actual].size() == 0){      
         D[actual].first = sections[actual].second - sections[actual].first + 1;
         D[actual].second = sections[actual].second - sections[actual].first + 1;
         Q.pop();
         flag = false;
         continue;
      }      
      FR(i,G[actual].size())
      {         
         if(visited[G[actual][i]])
         {
             if(D[G[actual][i]].first >= mayor)
                mayor = D[G[actual][i]].first;
             
             if(D[G[actual][i]].second <= menor)
                menor = D[G[actual][i]].second;
             flag = true;
         }        
         else if(!visited[G[actual][i]])
         {
            Q.push(G[actual][i]);            
            visited[G[actual][i]] = 1;
         }
      }
      if(flag)
      {
          D[actual].first =  sections[actual].second - sections[actual].first + 1 + mayor;
          D[actual].second =  sections[actual].second - sections[actual].first + 1 + menor;
          //cout<<actual<<": "<<D[actual].first<<" "<<D[actual].second<<endl;
          mayor = -1;
          menor = 100000000;
          Q.pop();
          flag = false;
      }
      
   }
   return D;
}

int calcSection(int pag,vp &sections)
{
    FR(i,sections.size())
       if(pag >= sections[i].first && pag <= sections[i].second) return i;
}

int main()
{
   int n;
   cin >> n;
   FR(i,n)
   {
      int sect;
      cin >> sect;
      vii G (sect);
      vp sections ;  
      int ini = 0;      
      FR(j,sect)
      {
         int a,b,c;
         cin >> a >> b >> c;                
         sections.push_back(make_pair(a,b));
         if(c != -1) G[c].push_back(j);
         else ini = j;        
      }
      vp D = bfsCost(ini, sections, G);
      int q;
      cin >> q;      
      cout<<"Caso "<<i+1<<":"<<endl;
      FR(k,q)
      {
          int pag;
          cin >> pag;
          int begining = calcSection(pag, sections);
          int mayor = D[begining].first - (pag - sections[begining].first);
          int menor = D[begining].second - (pag - sections[begining].first);         
          cout<<menor<<" "<<mayor<<endl;
      }  
   }
   return 0;
}
      
      

