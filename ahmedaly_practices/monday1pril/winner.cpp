# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <climits>
# include <map>
//# include <pair>
# define FR(i,n) for(int i = 0; i < n; i++)
# define PI  3.1415926535897931
# define PB push_back
#define D(x) cout<< #x " = "<<(x)<<endl

using namespace std;

struct jugadores{
  string name;
  int points;  
  bool operator < (const jugadores &otro) const {return points < otro.points;}
};



vector< pair<string,int> > queries;
map<string,int> game;
map<string,int> game2;
map<string,int> game3;

int main()
{
    int n = 0;
    cin >> n;
    string player;
    int points;   
    int greater =  -INT_MAX;
    for(int i = 0; i < n ; i++)
    {
          cin >> player >> points;
          game[player] += points;         
          queries.push_back(make_pair(player,points));
    }
    
    for(int i = 0; i < queries.size(); i++) if(game[queries[i].first] > greater) greater = game[queries[i].first];
    
    
    map<string,int>::iterator it ;
    for(it = game.begin(); it!=game.end(); ++it)
    {
       if(it->second == greater)
          game2[it->first] += 1;
    }
    
    for(int i = 0; i < queries.size(); ++i)
    {
        game3[queries[i].first] += queries[i].second;
        if(game3[queries[i].first] >= greater && game2[queries[i].first])
        {
           cout<<queries[i].first<<endl;
           break;
        }
    }   
    return 0;
}
    
