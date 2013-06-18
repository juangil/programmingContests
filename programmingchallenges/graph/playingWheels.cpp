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
    FR(i,4){
        string t1 = temp;
        string t2 = temp;
        t1[i] = t1[i]!='0'? t1[i]-1:'9';
        t2[i] = t2[i]!='9'? t2[i]+1:'0';
        children.push_back(t1);
        children.push_back(t2);
        //cout<<t1<<" "<<t2<<endl;
    }
    
    return children;
}
   
   

int bfsCost(string ini, string target, set<string> &forbidden)
{
    
   map<string, int> visit;
   queue< pair<string,int> > Q;
   Q.push(make_pair(ini, 0));
   int ans = 0;
   while(!Q.empty())
   {
      pair<string,int> actual = Q.front();
      Q.pop();
      if(visit[actual.first])continue;
      visit[actual.first] = 1;
      //cout<<actual.first<<endl;
      if (actual.first == target) return actual.second;     
      vs children = nextPerm(actual.first);
      FR(i,children.size())      
          if((forbidden.count(children[i]) == 0))
              Q.push(make_pair(children[i], actual.second + 1));
   }
   return -1;
}

string readString()
{
   string num;
   char dig;
   FR(i,4)
   {
      cin >> dig;
      num += dig;
   }
   return num;
}
   
int main()
{
   int n;
   cin >> n;
   FR(i,n)
   {
      string ini, target;
      int k;
      ini = readString();
      //cout<<ini<<" :"<<endl;
      //nextPerm(ini);
      target = readString();
      //cout<<target<<" :"<<endl;
      //nextPerm(target);
      cin >> k;
      set<string> forbidden;
      FR(j,k)
      {
          string f;
          f = readString();
          forbidden.insert(f);
      }
      cout << bfsCost(ini, target, forbidden) << endl;
   }
   return 0;
}
      
      

