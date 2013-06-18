# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <set>
# include <sstream>

using namespace std;

vector<string> horas;

int main()
{
    int a,b;
    for(int i = 0; i < 24; ++i)
    {
       a = i;
       for(int j = 0; j < 60; ++j)
       {
           b = j;
           if((a%10 == b/10) && (a/10 == b%10))
           {
              stringstream sa,sb;
              string numa,numb;
              sa << a;
              numa = sa.str();
              sb << b;
              numb = sb.str();              
              if(a < 10)                 
                  numa = "0"+numa;
              if(b < 10)
                  numb = "0"+numb;
              horas.push_back(numa+":"+numb);
           }
       }
    }
            
    string cad;
    cin >> cad;
    /*cout<<horas[horas.size()-1]<<endl;
    cout<<horas[horas.size()-2]<<endl;*/
    if(cad >= horas[horas.size()-1])
       cout<<horas[0]<<endl;
    else
      cout<<*upper_bound(horas.begin(), horas.end(), cad)<<endl;
    return 0;
}    
    
      
