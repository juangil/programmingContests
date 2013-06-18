# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# define PI 2*acos(0.0)

using namespace std;


double circles (double R,double r)
{
   double b = R - r;     
   double angle = 2.0*(atan2(r,b));
   double lon = PI*R*2.0;  
   double S = angle*R;   
   return lon/S;     
     
}

int main()
{
   int t;
   cin >> t;
   for(int i = 0; i < t ; i++)
   {
       double R = 0.0, n=0.0;
       double r=0.0;       
       cin >> R >> n;
       double hi = R/2.0, lo = 0.0;
       while (true)
       {
          r = lo + ((hi - lo)/2.0);         
          double target = circles(R,r);
          cout<<r<<" "<<target<<endl;
          double eps = 0.0000000001;          
          if(hi-lo < eps)
          { 
              printf("Case %d: %.10lf\n", i+1, r);
              break;
          }
          else if(target > n)
             lo = r;
          else
             hi = r;
       }
       
    }
     
   
   return 0;
}
   
   

