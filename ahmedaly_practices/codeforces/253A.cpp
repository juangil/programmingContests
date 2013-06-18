# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

using namespace std;

//bool myfunction (int i,int j) { return (i<j); }

struct mycomp{
  bool operator() (int i,int j) { return (i<j);}
}myobject;
    

int main()
{
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int boys, girls;
    cin >> boys >> girls;
    
    if(boys > girls)
    {
       int contb = boys, contg = girls;
       bool flag = false;
       for (int i = 0; i < boys + girls; i++)
       {
           if(flag == false && contb > 0)
           {
               cout<<"B";
               if(contg > 0)
                  flag = true;
               contb--;
               continue;
           }
           else if(flag == true && contg > 0)
           {
               cout<<"G";
               flag = false;
               contg--;
               continue;
           }
       }
       cout<<endl; 
    }     
    else
    {
       int contb = boys, contg = girls;
       bool flag = false;
       for (int i = 0; i < boys + girls; i++)
       {
           if(flag == false && contg > 0)
           {
               cout<<"G";
               if(contb > 0)
                  flag = true;
               contg--;
               continue;
           }
           else if(flag == true && contb > 0)
           {
               cout<<"B";
               flag = false;
               contb--;
               continue;
           }
       } 
       cout<<endl; 
    }
    return 0;    
    
}
