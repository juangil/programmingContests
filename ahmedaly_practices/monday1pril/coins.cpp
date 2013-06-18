# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

struct var
{
    char letter;
    int ocurrences;
    bool operator < (const var &otro) const {return ocurrences > otro.ocurrences;}
};
vector<var> vars;

int buscar(char a)
{ 
   for(int i = 0; i < vars.size(); i++)
   {
       if(vars[i].letter == a)
          return i;
   }
   return -1;
}

int main()
{
    string cad1;
    string cad2;
    string cad3;
    
    cin >> cad1;
    cin >> cad2;
    cin >> cad3;  
        
    if(cad1[1] == '<')
    {
        var x;
        x.letter = cad1[0];
        x.ocurrences =1;
        
        var y;
        y.letter = cad1[2];
        y.ocurrences = 0;
        
        vars.push_back(x);
        vars.push_back(y);
    }
    else if( cad1[1] == '>')
    {
        var x;
        x.letter = cad1[2];
        x.ocurrences = 1;
        
        var y;
        y.letter = cad1[0];
        y.ocurrences = 0;
        
        vars.push_back(x);
        vars.push_back(y);
    }
    
    if(cad2[1] == '<')
    {
       int idx = buscar(cad2[0]);
       if(idx >= 0)       
           vars[idx].ocurrences += 1;
       else
       {
           var x;
           x.letter = cad2[0];
           x.ocurrences =1;
           vars.push_back(x);
       }
       int idx2 = buscar(cad2[2]); 
       if(idx2 < 0)
       {
           var x;
           x.letter = cad2[2];
           x.ocurrences = 0;
           vars.push_back(x);
       }
     }
     else if(cad2[1] == '>')
     {
        int idx = buscar(cad2[2]);
        if(idx >= 0)       
           vars[idx].ocurrences += 1;
        else
        {
           var x;
           x.letter = cad2[2];
           x.ocurrences = 1;
           vars.push_back(x);
        }
       int idx2 = buscar(cad2[0]); 
       if(idx2 < 0)
       {
           var x;
           x.letter = cad2[0];
           x.ocurrences = 0;
           vars.push_back(x);
       }        
     }
     
     if(cad3[1] == '<')
    {
       int idx = buscar(cad3[0]);
       if(idx >= 0)       
           vars[idx].ocurrences += 1;
       else
       {
           var x;
           x.letter = cad3[0];
           x.ocurrences = 1;
           vars.push_back(x);
       }
     }
     else if(cad3[1] == '>')
     {
        int idx = buscar(cad3[2]);
        if(idx >= 0)       
           vars[idx].ocurrences += 1;
        else
        {
           var x;
           x.letter = cad3[2];
           x.ocurrences =1;
           vars.push_back(x);
        }        
     }
     
     sort(vars.begin(),vars.end());
     if(vars[0].ocurrences == vars[1].ocurrences || vars[0].ocurrences == vars[2].ocurrences || vars[1].ocurrences == vars[2].ocurrences )
     {
        cout<<"Impossible"<<endl;
        return 0;
     }
     for(int i = 0; i < 3; i++)     
        cout<<vars[i].letter;
     cout<<endl;  
     
     return 0;  
     
}
        
           
    
    
    
    
    
    
