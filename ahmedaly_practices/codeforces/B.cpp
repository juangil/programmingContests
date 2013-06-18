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

map<string, int> frec;

vector<jugadores> game;
int main()
{
    int n = 0;
    cin >> n;
    string player;
    int points;   
    bool flag = false;
    string winner2;
    int mayor = 0;
    for(int i = 0; i < n ; i++)
    {
          cin >> player >> points;
          //frec.insert(make_pair(player, ));
          int cont = 0;
          for(int  j = 0; j < game.size(); j++)
          {
              if(game[j].name == player)
               {
                    game[j].points += points;
                    flag = true; 
                    cont = j;
                    //cout<<"paso 1"<<endl;
                    if(game[cont].points > mayor)
                    {
                        winner2 =  game[cont].name;
                        mayor = game[cont].points;
                    }
                    
               }
              
                  
          }
            
          if(flag == false)
          {
                jugadores p;
                p.name = player;
                p.points = points;        
                game.push_back(p);
                if(p.points > mayor)
                {
                    winner2 =  p.name;
                    mayor = p.points;
                }
          }
          
         
          
    }
    sort(game.begin(),game.end());
    if(game[game.size()-1].points == game[game.size()-2].points)    
         cout<<winner2<<endl;
    else
         cout<<game[game.size()-1].name<<endl;    
    
    
    
    return 0;
}
    
    
