# include <cstdio>
# include <cstdlib>
# include <vector>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <iostream>
# define FR(i,n) for(int  i = 0;  i < n; i++)

using namespace std;

struct candy
{
     int cal;
     int price;
};


int main()
{
    int n, c;
    double m,p;
    while(true)
    {
         cin >> n >> m;
         vector<candy> all(n);
         if(n == 0 && m == 0.0) break;
         FR(i,n)
         {
            cin >> c >> p;
            all[i].cal = c;
            all[i].price = (int)round(p*100);
         }
         int current = (int)round(m*100);
         int dp[current + 1];
         dp [0] = 0;
         FR(i,current+1)
         {
           int mm = 0;
           FR(j,n)
           {              
              if(i >= all[j].price)
                        mm = max(all[j].cal+dp[i-all[j].price],mm);
           }
           dp[i] = mm;
         }
         cout<<dp[current]<<endl;
      }
 }  
                 
         
         
         
       
         
            
            
         
       
    
   
   
