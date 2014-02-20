# include <bits/stdc++.h>

using namespace std;

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

typedef unsigned long long int lli;
int main(){
    lli n;cin >> n;
    lli y = n - 1ULL;
    lli x = n - 1ULL;
    if(n == 0){
        cout<<1<<endl;
        return 0;
    }
    if(n == 1){
        cout<<4<<endl;
        return 0;
    }
    lli ans = 0;
    if((x*x) + (y*y) <= n*n)
        ans = x + y - 1ULL;
    else
        ans = x + y - 2ULL;
    
    //cout<<ans<<endl;
    cout<<(ans*4ULL) + 4ULL<<endl;
    return 0;
}
