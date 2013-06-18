# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <cmath>
# include <cstring>
# include <map>
# include <vector>
# include <algorithm>

using namespace std;

# define FR(i,n) for(int i = 0; i < n; i++)

double longitude(double h, double l)
{
   //cout<<(2.0*asin(l/(2.0*((h/2.0)+((l*l)/(8.0*h))))))<<endl;
   return ((h/2.0)+((l*l)/(8.0*h)))*(2.0*asin(l/(2.0*((h/2.0)+((l*l)/(8.0*h))))));
}

int main()
{
   double l,n,c;
   while(true){
      cin >> l >> n >> c;
      if(l + n + c + 3.0 < 0.000000001) break;
      double target = (1.0 + (n*c))*l;
      double y = 0.0, tmp = 0.0;
      double high = l/2.0, low = 0.0;
      double eps = 0.00001;
      //int cont = 0;
      while(true){     
        //if(cont == 100) break;
        y = ((high - low)/2.0) + low;
        tmp = longitude(y,l);
        //cout<<y<<" "<<tmp<<" "<<target<<" low: "<<low<<" high: "<<high<<endl;
        if(fabs(tmp-target) < eps) break;
        else{
          if(tmp < target) low = y;
          else high = y;
        }
        //cont++;
      }
      printf("%.3lf\n", y);
   }
  
   return 0;
}
