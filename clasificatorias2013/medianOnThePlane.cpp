using namespace std;
# include <cstdio>
# include <iostream>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

#define EPS 1e-6

struct myPoint{
    double x;
    double y;
    int id;
    
    myPoint(double x_, double y_, int id_): x(x_), y(y_), id(id_){}
    myPoint(){}
};

myPoint pivot;

double cross(const myPoint &a, const myPoint &b, const myPoint &c){
    return ((b.x - a.x)*(c.y - a.y)) - ((b.y - a.y)*(c.x - a.x));
}


bool anglecmp(const myPoint &p, const myPoint &q){
    double tcross = cross(pivot, p, q);
    return tcross > EPS;
}    

void solve(vector<myPoint> &p){
    for(int i = 1; i < p.size(); ++i){
        if(p[i].y < p[0].y || (p[0].y == p[i].y && p[i].x < p[0].x))
            swap(p[0], p[i]);
    }
    pivot = p[0];
    sort(p.begin()+1, p.end(), anglecmp);
}


int main(){
    int n;
    while(cin >> n){
        vector<myPoint> plane(n);
        for(int i = 0; i < n; ++i){
            double x,y;
            cin >> x >> y;
            plane[i] = myPoint(x, y, i+1);
        }
        solve(plane);
        cout<<plane[0].id<<" "<<plane[(plane.size()+1)/2].id<<endl;
    }
    return 0;
}
