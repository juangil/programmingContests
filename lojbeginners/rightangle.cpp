# include <cstdlib>
# include <iostream>
# include <cmath>
# include <cstdio>

using namespace std;

int main()
{
   int t;
   cin >> t;
   for(int i = 0; i < t; i++)
   {
      int a,b,c;
      scanf("%d %d %d", &a, &b, &c);
      if( a*a == (b*b) + (c*c))
         printf("Case %d: yes\n", i+1);
      else if(b*b == (a*a) + (c*c))
         printf("Case %d: yes\n", i+1);
      else if(c*c == (a*a) + (b*b))
         printf("Case %d: yes\n", i+1);
      else
         printf("Case %d: no\n", i+1);
    }
    return 0;
}
      
      
      
      
         
