// maximum width in a polygon using rotating calipers
# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <cmath>
# include <vector>
# include <limits>
# include <algorithm>
//# define PI = 3,1415926
 
using namespace std;
struct point
{
   double x;
   double y;
};
 
point rotate(point p,double angle){
//counterclockwise
   double xx=p.x*cos(angle) - p.y*sin(angle);
   double yy=p.x*sin(angle) + p.y*cos(angle);
   point q;
   q.x = xx;
   q.y = yy;
   return  q;
}
 
double angle(point u, point v)
{
  return acos(((u.x*v.x) + (u.y*v.y))/(sqrt((u.x*u.x)+(u.y*u.y))*sqrt((v.x*v.x)+(v.y*v.y))));
}
 
double convexPolygonMaxDistance(vector<point> polygon)
{
   long long int index_miny = 0, index_maxy = 0;
   double coor_miny = numeric_limits<double>::max( );
   double coor_maxy = -numeric_limits<double>::min( );
   double eps = 0.00000001;
   for(int i=0; i<polygon.size(); i++)
   {
       point a = polygon.at(i);
       //cout<<polygon.at(i).x<<" "<<polygon.at(i).y<<endl;
       if(a.y < coor_miny)
       {
          index_miny = i;
          coor_miny = a.y;
       }
       if(a.y > coor_maxy){
          index_maxy = i;
          coor_maxy = a.y;
       }
   }
   point vect ;
   vect.x = polygon.at(index_maxy).x -  polygon.at(index_miny).x;
   vect.y = polygon.at(index_maxy).y -  polygon.at(index_miny).y;
   double distance = sqrt(((vect.x)*(vect.x)) + ((vect.y)*(vect.y)));
   const double PI = 3.1415926;
   double rotated_angle = 0.0;
   point caliper_a;
   point caliper_b;
   caliper_a.x = 1.0;
   caliper_a.y = 0.0;
   caliper_b.x = -1.0;
   caliper_b.y = 0.0;
   //int cont=0;
   while(rotated_angle < PI){
      point edge_a;
      point edge_b;
      edge_a.x = polygon.at((index_maxy+1)%polygon.size()).x - (polygon.at(index_maxy)).x;
      edge_a.y = polygon.at((index_maxy+1)%polygon.size()).y - (polygon.at(index_maxy)).y;      
      edge_b.x = polygon.at((index_miny+1)%polygon.size()).x - (polygon.at(index_miny)).x;
      edge_b.y = polygon.at((index_miny+1)%polygon.size()).y - (polygon.at(index_miny)).y;
     
      double angle_a = angle(caliper_a, edge_a);
      double angle_b = angle(caliper_b, edge_b);
      
      double mini = min(angle_a, angle_b);
      caliper_a = rotate(caliper_a,(-1)*min(angle_a, angle_b));
      caliper_b = rotate(caliper_b,(-1)*min(angle_a, angle_b));
      if (abs(angle_a - mini) < eps)
          index_maxy = (index_maxy + 1)%polygon.size();
      if (abs(angle_b - mini) < eps)
          index_miny = (index_miny + 1)%polygon.size();
      point q = polygon.at(index_miny);
      point s = polygon.at(index_maxy);
      point w;
      w.x = q.x - s.x ;
      w.y = q.y - s.y ;
     
      distance = max(sqrt((w.x*w.x) + (w.y*w.y)), distance);      
      rotated_angle = rotated_angle + mini;
   }
   return distance;
}
 
int main()
{  
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {    
       int tam;
       cin>>tam;
       vector<point> polygon (tam);
       point q;
       cin>>q.x;
       cin>>q.y;      
       polygon[0]=q;
       
       for(int j=tam-1; j>0; j--)
       {  
          point p;        
          cin>>p.x;
          cin>>p.y;
         
          polygon[j]=p;
       }       
       printf("Case %d: %.3lf\n", i+1,convexPolygonMaxDistance(polygon));
    }
    return 0;
}
