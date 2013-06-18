using namespace std;
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<map>

struct point{
   double x,y;
   
   point(double a, double b): x(a), y(b){}
   point(){}
   point(const point &p) : x(p.x), y(p.y)    {}
   point operator + (const point &p) const { return point(x+p.x, y+p.y); }
   point operator - (const point &p) const { return point(x-p.x, y-p.y); }
   point operator * (double c) const { return point(x*c,   y*c  ); }
   point operator / (double c) const { return point(x/c,   y/c  ); }
};

double dot(point p, point q)     { return p.x*q.x+p.y*q.y; }
double dist2(point p, point q)   { return dot(p-q,p-q); }
double cross(point p, point q)   { return p.x*q.y-p.y*q.x; }

ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

// rotate a point CCW or CW around the origin
point RotateCCW90(point p)   { return point(-p.y,p.x); }
point RotateCW90(point p)    { return point(p.y,-p.x); }
point RotateCCW(point p, double t) {return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));}

double compute_area(const vector<point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(area / 2.0);
}

vector<point> compute_intersection(const map<point,vector<point> > segments){
   point p = segments.begin()->first;
}

int main(){
   
   
   return 0;
}
