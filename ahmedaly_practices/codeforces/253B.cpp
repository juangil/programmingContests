# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

using namespace std;

//bool myfunction (int i,int j) { return (i<j); }

struct card{
  int n;
  int idx;
  bool operator < (const card &otro) const {return n < otro.n;}
};

struct pareja{
  int x;
  int y;  
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, ai;
    vector<card> cards;
    cin >> n;
    for(int i = 0; i < 2*n; i++)
    {
        cin >> ai;
        card c;
        c.n = ai;
        c.idx = i+1;
        cards.push_back(c);
    }
    sort(cards.begin(), cards.end());
    bool flag = false;
    int cont = 0;
    vector<pareja> parejas;
    for(int i = 0; i < cards.size()-1; i+=2)
    {
        
        if(cards[i].n == cards[i+1].n)
        {
            pareja p;
            //cout<<cards[i].n<<" "<<cards[i+1].n<<endl;
            p.x = cards[i].idx;
            p.y = cards[i+1].idx;
            parejas.push_back(p);
            cont++;
        }
    }
    //cout<<cont<<endl;
    if(cont == n)
       for(int i = 0; i < n; i++)
           cout<<parejas[i].x<<" "<<parejas[i].y<<endl;
    else
       cout<<-1<<endl;
          
    return 0;
}
    
