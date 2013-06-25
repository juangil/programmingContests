# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <cmath>
# include <vector>
# include <set>

using namespace std;

#define FR(i,n) for(int i = 0; i < n; ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define MAXP 1010
typedef long long int lli;
double INF = 1e100;
double EPS = 1e-7;


struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return sqrt(dot(p-q,p-q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

int parent [MAXP];
int findSet(int a){
     if(a == parent[a])
          return a;
     else
          return parent[a] = findSet(parent[a]);
} 
void join(int a, int b){
     parent[findSet(a)] = findSet(b);
}

int main(){
     int t;cin>>t;
     FR(i,t){
          int n; double D;
          cin >> n >> D;
          vector< PT > myStars(n);
          FR(j,n){
               cin >> myStars[j].x >> myStars[j].y;
               parent[j] = j;
          }
          FR(j,n){
               FR(k,n)
                    if(dist2(myStars[j],myStars[k]) <= D) join(j,k);
          }
          set<int> myConstelations;
          FR(j,n)
               myConstelations.insert(findSet(j));
          cout<<"Case "<<i+1<<": "<<myConstelations.size()<<endl;
     }
     return 0;
}
