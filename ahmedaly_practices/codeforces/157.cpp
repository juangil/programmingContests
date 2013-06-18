# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <sstream>
//# include <pair>

using namespace std;
vector< pair<int,int> > v;


int main()
{
   int n,k;
   
   cin >> n >> k;
   
   for(int i = 0; i < n; ++i)
   {
      int x;
      int y;
      
      cin >> x >> y;
      
      v.push_back(make_pair(x,y));
   }
   double d = 0.0;
   for(int i = v.size()-1; i > 0; i--)
   {
      //cout<<v[i].first<<" "<<v[i-1].second<<endl;
      d += sqrt(((v[i].first - v[i-1].first)*(v[i].first - v[i-1].first)) + ((v[i].second- v[i-1].second)*(v[i].second- v[i-1].second)));
   }
   //cout<<d<<endl;
   printf("%lf\n", (d/50.0)*k);
   return 0;
}
          
      
      
      
