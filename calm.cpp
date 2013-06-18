# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# define PI 2*acos(0.0)

using namespace std;
int main()
{
   int t;
   cin >> t;
   for(int i = 0; i < t; i++)
   {
       double R,n;
       cin >> R >> n;
       double esp = PI/n;
       double a = sin(esp)*R;
       double b = cos(esp)*R;
       
       printf("Case %d: %.10lf\n", i+1, (a*b)/R);
   }
   return 0;
}
