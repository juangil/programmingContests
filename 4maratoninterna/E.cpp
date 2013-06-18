# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <cstring>
# define FR(i,n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long int lli;

int main()
{
   while(true)
   {
      int n;
      cin >> n;
      if (n == 0) break;
      double mayor = -1.0;
      pair<int,int> myNum;
      FR(i,n)
      {
         int a,b;
         cin >> a >> b;
         if(b*(log(a)) > mayor)
         {
            myNum.first = a;
            myNum.second = b;
            mayor = b*(log(a));
         }
      }
      //cout<<myNum.first<<" "<<myNum.second<<endl;
      int myPow [1000];
      memset (myPow,0,sizeof(myPow));
      myPow[999] = myNum.first;      
      lli result = myNum.first;
      int carry = 0;
      for(int i = 0; i < myNum.second - 1; i++)
      {
          
          for(int j = 999; j >= 0; j--)
          {
              if(myPow[j] == -1)
              {
                  myPow[j] = carry;
                  carry = 0;
                  break;
               }           
              result = (myNum.first*myPow[j])+carry;
              int digit = result%10;
              carry = result/10;
              myPow[j] = digit;
              //cout<<carry;
              //cout<<digit;
           }
           //cout<<endl;
      }
      bool flag = false;
      FR(i,1000) if(myPow[i] == -1 or myPow[i]==0) myPow[i]=-1;
        else break;
      FR(i,1000)     
         if(myPow[i] != -1) cout<<myPow[i];    
      cout<<endl;   
    }
    return 0;
}
