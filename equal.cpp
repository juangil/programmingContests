using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include <limits> 
#include <queue> 
#include <stack> 
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#define MP 5005
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,v) for( typeof (v.begin()) x = v.begin();x!=v.end();++x)
#define D(x) cout<< #x " = "<<(x)<<endl

struct point{
    double x,y;
    point(){}
    point(double X, double Y): x(X),y(Y){}
    
    double norm(){
        return sqrt(x*x + y*y);
    }
    
    point mult_es(double e){
        return point(x*e,y*e);
    }
    
    double prod(point o){
        return x*o.x + o.y*y;
    }
    point sub(point o){
        return point(x-o.x, y-o.y);
    }
    point add(point o){
        return point(x+o.x, y+o.y);
    }
    
    double angle(point o){
        double t = this->prod(o);
        return acos(t / this->norm()*o.norm());
    }
    
    double cross(point 0){
        return x*o.y - o.x*y;
    }
    
    point rotate(double angle){
      x = (x*cos(angle)) - (y*sin(angle));
      y = (x*sin(angle)) + (y*cos(angle));
    }
    
    point intersetion(point o){
        double den = this->cross(o);
        if(fabs(den) < eps){
            return point((1<<30),(1<<30));
        }
        point 
    }

};

point a,b,c;

int main(){

    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y and a.x!=0 and a.y!=0 and b.x!=0 and b.y!=0 and c.x!=0 and c.y!=0){
        point v1 = a.sub(b),v2 = a.sub(c),v3 = b.sub(a), v4 = b.sub(c),v5 = c.sub(a) v6 =  c.sub(b);
        double a1 = v1.angle(v2),a2 = v3.angle(v4),a3 =  v5.angle(v6);
        double mm = min(min(a2,a1),a3);
        point base,l1,l2;
        if(mm==a1){ 
            base = a;
            l1 = b;
            l2 = c;
        }
        else if(mm==a2){ 
            base = b;
            l1 = a;
            l2 = c;
        }else{ 
            base = c;
            l1 = a;
            l2 = b;
        }
        double delta = mm/100000.0;
        double i = delta;
        int inc = (l1.sub(base).cross(l2.sub(base)) > 0)1:-1;
        while(i < mm){
           point r1 = intersection(l1.sub(base).rotate(i*inc).intersetion(l1.sub(l2).rotate(i*inc)));
           point mio = r1.sub(l1);
           point mio2 = l2.sub(l1);
           double ann = mio.angle(mio2);
           if(fabs(ann - i)< eps) break;
           i+=delta;
        }
        
        cout<<i<<endl;
    }
    
   
   return 0;
}
