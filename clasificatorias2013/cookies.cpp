using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <cstdio>
#include <algorithm>

#define FR(i,n) for(int i = 0; i < n; ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
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
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
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

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
/*PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}*/

PT ComputeLineIntersection(PT p1, PT p2, PT p3, PT p4) {
     PT p2_p1=p2-(p1);
	PT p4_p3=p4-(p3);
	double den=cross(p2_p1,(p4_p3));
	if (fabs(den)< EPS)//the lines are parallel or coincident
		return PT();
	PT p1_p3=p1-(p3);
	double num= cross(p4_p3,(p1_p3));
	double ua=num/den;
	return (p2_p1*ua)+(p1);
}

// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

/*bool PointInPolygon(vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || 
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

bool PointOnPolygon(vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}*/

double ccw(PT a,PT b,PT c){
		return cross(a-(b),(c-(b)));
}


int PointInPolygon(vector<PT> &p, PT t){
		int mask=0;
		for(int i=0;i<p.size();i++){
			double z=ccw(p[i],p[(i+1)%p.size()],t);
			if (fabs(z)<EPS)
				return false;
			else if (z<0)
				mask |= 1;
			else if (z>0)
				mask |= 2;
			if (mask==3)
				return false;
		}
		return true;
	}

double ComputeSignedArea(vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}



vector<PT> chipsInsideCuts(vector<PT> &myChips, vector< pair<PT,PT> > &mySegments){
   vector<PT> newChips;
   for(int i = 0; i < myChips.size(); ++i){
      bool flag = false;
      for(int j = 0; j < mySegments.size(); ++j){
          PT tmp = ProjectPointSegment(mySegments[j].first, mySegments[j].second, myChips[i]);
          if(sqrt(dot(myChips[i] - tmp, myChips[i] - tmp)) < EPS){
             flag = true;
             break;
          }
       }
       if(flag == false) newChips.push_back(myChips[i]);
   } 
   return newChips;
}

vector<PT> sutherland_hodgman(vector<PT> line,vector<PT> poly, int flag){
     vector<PT> output;
	PT S = poly[poly.size()-1];
	for(int i=0;i<poly.size();i++){
		PT E = poly[i];
		double ecross = cross((line[1]-(line[0])),(E -(line[0])));
		double scross = cross((line[1]-(line[0])),(S -(line[0])));
		if (fabs(ecross)<EPS)
			output.push_back(E);
		else if (ecross*flag > EPS){
			if (scross*flag < -EPS)
				output.push_back(ComputeLineIntersection(S,E,line[0],line[1]));
			output.push_back(E);
		}
		else if(scross*flag>EPS)
			output.push_back(ComputeLineIntersection(S,E,line[0],line[1]));
		S = E;
	}
	return output;
}

vector< vector<PT> > computeNewPolygons(pair<PT,PT> &line,vector<PT> &poly){
     vector<PT> myLine (2);
     myLine[0] = line.first;myLine[1]=line.second;
     vector<PT> uno=sutherland_hodgman(myLine, poly,1);
	vector<PT> dos=sutherland_hodgman(myLine, poly,-1);
	int amount=(uno.size()>2)?1:0;
	amount+=(dos.size()>2)?1:0;
	vector< vector<PT> > ret(amount);
	int index=0;
	if (uno.size()>2)
		ret[index++]=uno;
	if (dos.size()>2)
		ret[index++]=dos;
	return ret;
}

double computeMaxDensity(vector< vector<PT> > &myPolygons, vector<PT> &newChips){
   double mayor = -10.0;
   foreach(pol,myPolygons){
      int npoints = 0;
      for(int j = 0; j < newChips.size(); ++j)
         if(PointInPolygon((*pol),newChips[j])) npoints += 1;
      double area = ComputeArea((*pol));
      double density = ((double)npoints)/area;
      if(density > mayor) mayor = density;
   }
   return mayor;
}

int main(){
   //ios_base::sync_with_stdio(false);
   //cin.tie(NULL);
   int l,c,k;
   while(cin>>l>>c>>k and (l + c + k) != 0){      
      vector< vector<PT> > ans;   
      vector<PT> myChips (c);
      vector< pair<PT,PT> > mySegments(k);
      vector<PT> mySquare (4);
      mySquare[0] = PT(0,0);
      mySquare[1] = PT(l,0);
      mySquare[2] = PT(l,l);
      mySquare[3] = PT(0,l);
      ans.push_back(mySquare);
      for(int i = 0; i < c; ++i)
         cin >> myChips[i].x >> myChips[i].y;
      
      for(int i = 0; i < k; ++i){
         PT p1; PT p2;
         cin >> p1.x >> p1.y >> p2.x >> p2.y;
         mySegments[i]= make_pair(p1,p2);
         vector< vector<PT> > tmp;
         foreach(pol,ans){
              vector< vector<PT> > result = computeNewPolygons(mySegments[i],(*pol));
              FR(j, result.size())
                   tmp.push_back(result[j]);
         }
         ans = tmp;
      }
      vector<PT> newChips = chipsInsideCuts(myChips, mySegments);
      double A = computeMaxDensity(ans, newChips);
      printf("%.3lf\n", A);
   }
   //cout<<"termino"<<endl;
   return 0;
}
