# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# define FR(i,n) for(int i = 0; i < n; i++)
# define PI 2*acos(0.0)


using namespace std;



int main()
{
   int t = 0;
   scanf("%d", &t);
   
   FR(i, t)
   {
      double r = 0.0;
      double area = 0.0;
      scanf("%lf", &r);
      
      area = ((2.0*r)*(2.0*r)) - (PI*(r*r));        
      
      printf("Case %d: %.2lf\n", i+1,area);  
   }
   return 0;
 }   
      
