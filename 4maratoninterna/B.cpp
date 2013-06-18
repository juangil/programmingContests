# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

typedef long long int lli;

lli bigMod(lli b, lli p, lli m)
{
   lli mask = 1;
   lli pow2 = b%m;
   lli r = 1;
   while(mask)
   {
       if(p & mask) r = (r * pow2) % m;
       pow2 = (pow2 * pow2) % m;
       mask <<= 1;
   }
   return r;
}

int main()
{
   int t;
   cin >> t;
   lli m = 1000000000;
   for(int  i = 0; i < t; ++i)
   {
       lli b,p;
       cin >> b >> p;
       cout<<bigMod(b,p,m)<<endl;
   }
   return 0;
}
   
