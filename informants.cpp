# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <map>
# include <vector>

using namesapce std;

int main(){
     int n,a;
     while(cin >> i >> a and (i + a)!= 0){
          vector< pair<int,int> > myAgents (n,make_pair(0,0));
          for(int i = 0; i < a; ++i){
               int x,y;
               cin >> x >> y;
               if(y > 0) myAgents[y-1].first += 1;
               else myAgents[abs(y)-1].second += 1;
          }
          for(int i = 0; i < )
          
