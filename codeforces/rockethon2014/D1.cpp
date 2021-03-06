# include <bits/stdc++.h>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

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

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

// determine if line segment from a to b intersects with 
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}


PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

int main(){
     double n,m;
     cin >> n >> m;
     vector< pair<PT,PT> > mysegmentX;
     vector< pair<PT,PT> > mysegmentY;
     for(int i = 0; i < n; ++i){
          pair<PT,PT> mysegment;
          cin >> mysegment.first.x;
          cin >> mysegment.first.y;
          double tmp;
          cin >> tmp;
          mysegment.second.x = mysegment.first.x;
          mysegment.second.y = mysegment.first.y + tmp;
          mysegmentY.push_back(mysegment);
     }
     for(int i = 0; i < m; ++i){
          pair<PT,PT> mysegment;
          cin >> mysegment.first.x;
          cin >> mysegment.first.y;
          double tmp;
          cin >> tmp;
          mysegment.second.x = mysegment.first.x + tmp;
          mysegment.second.y = mysegment.first.y;
          mysegmentX.push_back(mysegment);
     }
     int cont = 0;
     double mayor = -INF;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               PT a = mysegmentY[i].first;
               PT b = mysegmentY[i].second;
               PT c = mysegmentX[j].first;
               PT d = mysegmentX[j].second;
               double tmp = -INF;
               if(SegmentsIntersect(a, b, c, d)){
                    PT mio = ComputeLineIntersection(a,b,c,d);
                    
                    double d1 = dist2(mio,a);
                    //cout<<d1<<"    "<<mio.x<<" "<<mio.y<<" "<<a.x<<" "<<a.y<<endl;
                    double d2 = dist2(mio,b);
                    //cout<<d2<<"    "<<mio.x<<" "<<mio.y<<" "<<b.x<<" "<<b.y<<endl;
                    double d3 = dist2(mio,c);
                    //cout<<d3<<"    "<<mio.x<<" "<<mio.y<<" "<<c.x<<" "<<c.y<<endl;
                    double d4 = dist2(mio,d);
                    //cout<<d4<<"    "<<mio.x<<" "<<mio.y<<" "<<d.x<<" "<<d.y<<endl;
                    tmp = min(min(d1,d2), min(d3,d4));
                    //cout<<endl;
               }
               else cont++;
               if(tmp > mayor){
                    mayor = tmp;
               }
          }
     }
     if(cont == n*m) cout<<0<<endl;
     else cout<<(int)mayor<<endl;
     return 0;
}
