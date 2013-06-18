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
      int n, total=0;
      scanf("%d", &n);
      FR(j,n)
      {
         int amount;
         cin >> amount;         
         if (amount < 0)
            continue;
         else
            total += amount;
         
      }
      printf("Case %d: %d\n", i+1,total);  
   }
   return 0;
 }   
      
