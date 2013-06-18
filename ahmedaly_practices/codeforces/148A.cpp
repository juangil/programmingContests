# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <set>


using namespace std;


set<int> myset;

int main()
{
   int k,l,m,n,d;
   
   cin >> k >> l >> m  >> n >> d ;
   for(int i = k; i <= d; i+=k)
       myset.insert(i);
       
   for(int i = l; i <= d; i+=l)
       myset.insert(i);
   
   for(int i = m; i <= d; i+=m)
       myset.insert(i);
       
   for(int i = m; i <= d; i+=n)
       myset.insert(i);
   
   cout<<myset.size()<<endl;
   
   return 0;
   
}  
   
   
   
   
