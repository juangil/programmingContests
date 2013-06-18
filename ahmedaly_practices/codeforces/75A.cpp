# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <sstream>





using namespace std;


map<char, int> frec;

int foo (string num)
{
   
   for(int i = 0; i < num.length(); i++)
   {
       if(num[i] == '0')
       {
          i--;
          num.erase(num.begin()+i);
          }
   }
   //cout<<atoi(num.c_str())<<endl;
   return atoi(num.c_str());
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    
    int c = a + b;
    
    string numa;
    string numb;
    string numc;
    
    std::stringstream sa,sb,sc;
    sa << a;
    numa = sa.str();
    
    sb << b;
    numb = sb.str();
    
    sc << c;
    numc = sc.str();   
    cout<<endl;
    //cout<<foo(numc)<<" "<<foo(numa)<<" "<<"+"<<" "<<foo(numb)<<endl;
    if(foo(numc) == foo(numa) + foo(numb))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    return 0;
}
    
   
