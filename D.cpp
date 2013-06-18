# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <string>

using namespace std;

int main()
{
    string culebra;
    int flechas;
    cin >> culebra;
    cin >> flechas;
    string corazoncito = "";
    for(int i  =0 ;i< culebra.size();++i) culebra[i] = tolower(culebra[i]);
    for( int fantasmita = 0; fantasmita < culebra.size() ; ++fantasmita)
    {
       char dedito = culebra[fantasmita];
       
       if(dedito < flechas + 97)
          corazoncito.push_back(toupper(dedito));
       else
          corazoncito.push_back(tolower(dedito));
     }
     cout << corazoncito <<endl;
     return 0;
     
}
