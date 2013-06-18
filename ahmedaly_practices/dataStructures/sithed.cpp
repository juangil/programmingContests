# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <string>
# include <set>

using namespace std;

# define FR(i,n) for(int i = 0; i < n; ++i)
# define fr(i,j,n) for(int i = j; i < n; ++i)
# define freach(x,v) for(typeof(v.begin()) x = v.begin(); x != v.end(); ++x)

set<string> ans ;

struct trie{
   
   int G[MAXS][26];
   int state_count;
   
   trie(){
      clear();
   }
   
   void clear(){
      state_count = 1;
      memset(G[0], -1, sizeof(G[0]));
   }
   
   void insert(string s){
      int state = 0; //root
      FR(i,s.size()){
         int next = s[i] - 'a';
         if(G[state][next] == -1){ // add new  state
            G[state][next] = state_count;
            memset(G[state_count], -1, sizeof(G[state_count]));
            state_count++;
         }
         state = G[state][next];
      }
   }

};

int visited [MAXS];
memset(visited, 0, sizeof(visited));
void dfs(string q, trie t)
{
   int ini = 0;
   
       
    

int main()
{
   int n;
   cin >> n;
   trie t;
   FR(i,n){
     string word;
     cin >> word;
     word += "$";
     t.insert(word);
   }
   int k;
   cin >> k;
   set<string> myQueries;
   FR(i,k){
     string query;
     cin >> query;
     myQueries.insert(query);
   }
   int cont = 1;
   freach(it,myQueries)
   {
       string q = *it;
       myMatchings = dfs(q,t);
       ans.clear();
       printf("Case #%d:\n", cont);
       freach(it2,ans){
          string q2 = *it2;
          printf("%s\n", q2);
       }
    }
    return 0;
}
     

