# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>

using namespace std;

int main()
{
   int t;
   cin >> t;
   for(int i = 0; i < t ; i++)
   {
       int a,b;
       cin >> a >> b;
       
       int time = 4*abs(a-b) + 9 +(4*a) + 10;
       printf("Case %d: %d\n", i+1, time);
   }
   return 0;
}
   
   

