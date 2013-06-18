# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# define FR(i,n) for(int i = 0; i < n; i++)


using namespace std;



int main()
{
   int t = 0;
   scanf("%d", &t);
   
   FR(i, t)
   {
      int n, m;
      scanf("%d %d", &n, &m);
      int max = 0;
      if(n == 1 || m == 1)
         max = m*n;
      else if (n == 2)
      {
         if(m%2 == 0)
            max = ceil(m/4.0)*4;
         else
            max = ceil(m/2.0)*2;
      }
      else if (m == 2)
      {
         if(n%2 == 0)
            max = ceil(n/4.0)*4;
         else
            max = ceil(n/2.0)*2;
      }
      else if(n > 2 && m > 2)
         max = ceil((n*m)/2.0);
      printf("Case %d: %d\n", i+1,max);
   }
   return 0;
 }   
      
                  
            
            

