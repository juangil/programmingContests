# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <sstream>
# define PI 3.1415926535897931



using namespace std;



int main()
{
   string a;
   string b;
   
   cin >> a;
   cin >> b;
   
   if(a.length() != b.length()) {cout<<"NO"<<endl; return 0;}
   int cont = 0;
   for(int i = 0; i < a.size(); i++)
   {
       if(b[i] == a[a.size() - 1 - i]) cont++;
   }
   if(cont == a.length()) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;   
       
   return 0;
}
   
