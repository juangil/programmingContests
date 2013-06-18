# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <string>
# include <map>

using namespace std;




map<string,int> pos = {{"TTT",0}, {"TTH",0}, {"THT",0}, {"THH",0}, {"HTT",0}, {"HTH",0}, {"HHT",0}, {"HHH",0}};

std::map<std::string,int> mymap = {
                { "alpha", 0 },
                { "beta", 0 },
                { "gamma", 0 } };

/*pos["TTT"] = 0;
pos["TTH"] = 0;
pos["THT"] = 0;
pos["THH"] = 0;
pos["HTT"] = 0;
pos["HTH"] = 0;
pos["HHT"] = 0;
pos["HHH"] = 0;*/


void search(string toss)
{
    for(int i = 0; i < 40; i ++)
    {
        for(int j=i+1; j< 40; j++)
        {
            for(int k = j+1; k < 40; k ++)
            { 
                    char three = toss[i]+toss[j]+toss[k];
                    map.find(three).second;                 
            }
        }
    }
    return;
}
                    
            
                    
            
       

int main()
{
    int p,n;
    cin >> p;
    for(int i = 0; i < p; i++)
    {
            cin >> n;
            string toss;            
            cin >> toss;
            search(toss);
            cout<<n<<endl;
            //cout<<" "<<pos["TTT"].second<<" "<<pos["TTH"].second<<" "<<pos["THT"].second<<" "<<pos["THH"].second<<pos["HTT"].second<<" "<<pos["HTH"].second<<" "<<pos["HHT"].second<<" "<<pos["HHH"].second<<endl;
    }  
    return 0;
}
