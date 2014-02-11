# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <cmath>

using namespace std;


int main()
{
   int year;
   cin >> year;
   year++;
   while(true)
   {
      
      if((year/1000 != (year/100)%10) && (year/1000 != (year/10)%10) && (year/1000 != year%10) && ((year/100)%10 != (year/10)%10) && ((year/100)%10 != year%10) && ((year/10)%10 != year%10))
      { 
        cout << year <<endl;
        break;
      }
      year ++;
   }
   return 0;
   
}
     
