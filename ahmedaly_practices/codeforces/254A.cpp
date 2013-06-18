# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <pair>

using namespace std;

//bool myfunction (int i,int j) { return (i<j); }

pair<int,int> mes_dias;

struct olympiad{
  int month;
  int day;
  int jury;
  int duration;
  pair<int,int> beginday;
  bool mayor = false;
  bool operator < (const olympiad &otro) const {
       if(beginday.first == otro.beginday.first)        
             return beginday.second < otro.beginday.second;  
       else
          return beginday.first < otro.beginday.first;
  }      
};


mes_dias meses [12] = {make_pair(1,31),make_pair(2,28),make_pair(3,31),make_pair(4,30),make_pair(5,31),make_pair(6,30),
                       make_pair(7,31),make_pair(8,31),make_pair(9,30),make_pair(10,31),make_pair(11,30),make_pair(12,31)};
                       

mes_dias  BeginPrepDay(int month, int day, int duration)
{
     while(true)
     {
         if(day - duration <=0)
         {  
            duration -= day;
            if(month <= 0)              
            day = meses[month-1].second; 
            month--;
         }
         else
           return make_pair(month,day - duration);
     }
}
         

int main()
{
    int n;
    cin >> n;
    int m,d,p,t;
    int mayor = 0;
    vector<olympiad> myolymp;
    for(int i = 0, i < n; i++)
    {
        cin >> m >> d >> p >> t;
        int actual = p;
        if(actual > mayor)
           mayor = actual;
        olympiad o;
        o.month = m;
        o.day = d;
        o.jury = p;
        o.duration = t;
        o.beginday = BeginPrepDay(m, d, t);   
        myolymp.push_back(o);
    }
    sort(myolymp.begin(), myolymp.end());
    int jurynum = mayor;
    for(int i = 1; i < myolymp.size()-1; i++)
    {
        //int begin1 = myolymp[i].day - myolymp[i].duration;
        mes_dias begin= BeginPrepDay(myolymp[i].month, myolymp[i].day, myolymp[i].duration);        
        if(begin.second <  myolymp[i-1].day)
           jurynum += myolymp[i].jury;
        else
           continue;
    }
    cout<<jurynum<<endl;
    return 0;
}
        
    
    
    
    
    
    
    
    
    
    
        
