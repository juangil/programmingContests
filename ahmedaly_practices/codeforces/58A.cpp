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
   
   cin >> a;
   int idx = -1;
   for(int i = 0; i < a.length(); i++)
   {   if(a[i] == 'h'){ idx = i; break;}  }
   if(idx < 0){cout<<"NO"<<endl; return 0;}
   
   int idxe = -1;
   for(int i = idx; i < a.length(); i++)
   {    if(a[i] == 'e'){ idxe = i; break;} }
   //cout<<idxe<<endl;
   if(idxe < 0){cout<<"NO"<<endl; return 0;}       
   
   int idxl1 = -1;
   for(int i = idxe; i < a.length(); i++)
   {    if(a[i] == 'l'){ idxl1 = i; break;}}
   //cout<<idxl1<<endl;
   if(idxl1 < 0){cout<<"NO"<<endl; return 0;}
   
   int idxl2 = -1;
   for(int i = idxl1+1; i < a.length(); i++)
   {    if(a[i] == 'l'){ idxl2 = i; break;}}
   //cout<<idxl2<<endl;
   if(idxl2 < 0){cout<<"NO"<<endl; return 0;}
   
   int idxo = -1;
   for(int i = idxl2; i < a.length(); i++)
   {    if(a[i] == 'o'){ idxo = i; break;}}
   //cout<<idxl2<<endl;
   if(idxo < 0){cout<<"NO"<<endl; return 0;}
   
   cout<<"YES"<<endl;
   return 0;
}
   
