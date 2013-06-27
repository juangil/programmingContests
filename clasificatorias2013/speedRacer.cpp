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
#define MAXD 1.79769e+308
#define EPS 1e-7

double myFun(double &v,double &a,double &b,double &c){
     return (a*v*v*v) + (b*v*v) + (c*v);
}

int mycmp(double y1, double y2){//thanks pin3da you open my eyes
     return (y1 <= y2 + EPS)?(y1 + EPS < y2)? -1:0:1;
}

int main(){
     double a,b,c,d,m,t,target;
     while(cin >> a >> b >> c >> d >> m >> t){
          target = (t/m) - d;
          double low = 0.0;
          double high = MAXD;
          double ans = 0.0;
          while(mycmp(low,high) == -1){//while low < high
               double mid = (low+high)/2.0;
               double fmid = myFun(mid, a, b, c);
               if(mycmp(fmid,target) == -1)//if the function evaluated in the value is less than target, then we have to raise the low limit
                    low = mid;
               else if(mycmp(fmid,target) == 1)//this happens when the function evaluated in mid is more than target, then we have to lower high
                    high = mid;
               else{ //this happens when the evaluated in mid and the target are the same with a tolerance value, we find our answer.
                    ans = mid;
                    break;
               }
          }
          ans=(floor(ans*100.0))/100.0;
          printf("%.2lf\n", ans);
     }   
     return 0;
}
          
