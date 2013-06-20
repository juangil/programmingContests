# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# define FR(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int divi = 10000; 

typedef vector<double> pol;


double polyn_at(pol p, pol q,double val)//polynomial calculation with honer's method
{
   double bn = p[p.size() - 1];
   double acum = bn;
   double bn2 = q[q.size() - 1];
   double acum2 = bn2;
   for(int i = p.size() - 2; i >= 0; i--)//the denominator and the nume are equal in lenght
   {
       acum = p[i] + (acum*val);
       acum2 = q[i] + (acum2*val);    
   }
   
   return acum/acum2;
}  
  
double num_integr(pol p1, pol p2, pol q1, pol q2, double d, double w)//Area under a curve
{
   double delta = w/(double) divi;  
   double acum = 0.0 , acum2 = 0.0; 
   double xi = delta/2.0;
   double tmp = 0.0, tmp2 = 0.0;   
   
   FR(i,divi)
   { 
      tmp = polyn_at(p1,q1,xi);
      if(tmp > d)             
         acum += (d - tmp)*delta;
      xi += delta;
   }     
   xi = delta/2.0;
   FR(j,divi)
   {
      tmp = polyn_at(p2,q2,xi); 
      if(tmp > d)      
         acum2 += (d - tmp)*delta;
      xi += delta;
   }
   return fabs(acum -acum2);
   
}

double search(pol p1, pol p2, pol q1, pol q2, double d, double target, double w)//binary search
{
   double lo = 0.0;
   double eps = 0.0000001;
   double hi = (-1.0)*d; 
   double depth = 0.0;
   while(true)
   {
      depth = lo + ((hi - lo)/2.0);
      //cout<<depth<<endl;
      double area = num_integr(p1, p2, q1, q2, depth, w);
      double dif = area - target;
      //cout <<"area: "<<area<<" target: "<<target<<"dif: "<<(fabs(area - target)<eps)<<endl;      
      if(fabs(area - target) < eps)
        return depth;      
      if(area < target)            
         lo = depth;            
      else       
         hi = depth;  
    }
}
      
      
int main()
{
   double w = 0,d = 0,a = 0,k = 0;
   //freopen("ep.in","r",stdin);
   while(scanf("%lf %lf %lf %lf", &w, &d, &a, &k)!=EOF)
   {
       pol p1(k+1);
       pol p2(k+1);
       pol q1(k+1);
       pol q2(k+1);         
       
       FR(j,k+1)
         cin >> p1[j];
         
       FR(m,k+1)
         cin >> q1[m];
         
       FR(n,k+1)
         cin >> p2[n];
         
       FR(o,k+1)         
         cin >> q2[o];
       
       printf("%.5lf\n",fabs(search(p1, p2, q1, q2, d, a, w)));
    }   
    return 0;
}
           
         
   
