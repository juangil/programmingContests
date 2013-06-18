# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>


using namespace std;


map<char, int> frec;

int main()
{
   string name;
   cin >> name;
   
   for(int i = 0; i < name.length(); ++i)  
   {
      if(frec[name[i]])         
          continue;         
      
      frec[name[i]] = 1;
   }
   
   map<char,int>::iterator it ;
   int cont = 0;
   for(it = frec.begin(); it!=frec.end(); ++it)
   {
      cont += it->second;
   }
   //cout<<cont<<endl;
   if(cont%2 == 0)
      cout<<"CHAT WITH HER!"<<endl;
   else
      cout<<"IGNORE HIM!"<<endl;
   return 0;
   
}  
   
   
   
   
