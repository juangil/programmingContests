using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
//#include<istream>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
# include <sstream>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vss;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;
typedef map<string,int> msi;
typedef long long int lli;

bool mycmp (pair<string,int> a,pair<string,int> b) { return (a.second<b.second); }

vector< pair<string,int> >  table;

string convertInt(lli number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

set<lli> lucky;
//lucky.insert(0);
void gen_lucky(lli a=0){
   if(a>1000000000L) return;
   lli x = (a*10) + 4;
   lli y = (a*10) + 7;
   lucky.insert(x);
   lucky.insert(y);
   //interval.PB(MK(x,y));   
   gen_lucky(x);
   gen_lucky(y);
}

int main()
{
   lli a,b;
   gen_lucky();
   cin >> a >> b;
   lli total = 0;
   std::set<lli>::iterator it,it2;
   //lli c = 0, d = 0;
   if(a == b)
   {
      if(lucky.count(a) == 0)
      {
         it = lucky.upper_bound(a);
         cout<<*it<<endl;
      }
      else cout<<a<<endl;
      return 0;
   }   
   for(it = lucky.begin(); it != lucky.end(); it++)
   {
      if(a <= *it){
         total += (((*it)-a)+1)*(*it);
         //cout<<total<<endl;
         std::set<lli>::iterator itx = it;
         itx++;
         for(it2 = itx; it2 != lucky.end(); it2++)
         {
            std::set<lli>::iterator itx2 = it2;
            //cout<<*it2<<endl;
            if( b <= *it2 )
            {   
               //cout<<"paso1"<<endl;         
               if(b <= *it)
               {
                   total -= ((*it - b))*(*it);
                   break;
               }
               lli tmp = (b - *(--itx2))*(*it2);
               total += tmp;
               //cout<<total<<endl;
               break;
            }
            //cout<<"paso2"<<endl;
            total += (*(it2) - *(--itx2))*(*it2);
         }
         break;
      }
    }
    cout<<total<<endl;
    return 0;  
}
