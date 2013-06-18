# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# define FR(i,n) for(int i = 0; i < n; i++)

typedef long long int lli;

using namespace std;


int main()
{
   int t = 0;
   cin >> t;
   
   FR(i, t)
   {
      lli  n, position, x, y, dif;
      cin >> n;
      position = ceil(sqrt(n));
      //cout << position <<endl;
      if(position%2 == 0)
      {
          
          dif = (position*position) - n;
          if(dif >= position)
          {
             x = position - (((position*position) - (position-1)) - n);
             y = position;
          }
          else
          {
             x = position;
             y = position - (n - ((position*position) - (position - 1)));
          }
       }
       else
       {
          dif = (position*position) - n;
          if(dif >= position)
          {
             x = position;
             y = position - (((position*position) - (position - 1)) - n);
          }
          else
          {
             x = position - (n - ((position*position) - (position - 1)));
             y = position;
          }
       }
       cout<<"Case "<<i+1<<": "<<x<<" "<<y<<endl;
    }
    return 0;
}
            
              
      
   




