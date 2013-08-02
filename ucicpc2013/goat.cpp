# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <iomanip>
# include <limits>
using namespace std;

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

const DOUBLE EPS = 1e-9;

struct point{
     double x;
     double y;
     point() {}
     point(double xx,double yy) : x(xx), y(yy){}
     double dist2point(const point &p){return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));}
};

struct LPSolver{
     int m,n; 
     VI B, N;
     VVD D;
     
     LPSolver(const VVD &A, const VD &b, const VD &c):
          m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, VD(n+2)){
          for(int i = 0; i < m; ++i) for(int j = 0; j <n; ++j) D[i][j] = A[i][j];
          for(int i = 0; i < m; ++i) {B[i] = n + i; D[i][n] = -1; D[i][n+1] = b[i];}
          for(int j = 0; j < n; ++j) {N[j] = j; D[m][j] = -c[j];}
          N[n] = -1; D[m+1][n] = n;
     }
     
     void Pivot(int r, int s){
          for(int i = 0; i < m+2; ++i) if(i != r)
               for(int j = 0; j < n+2; ++j) if(j != s)
                    D[i][j] -= D[r][j]*D[i][s] / D[r][s];
          for(int j = 0; j < n+2; ++j) if(j != s) D[r][j] /= D[r][s];
          for(int i = 0; i < m+2; ++i) if(i != r) D[i][s] /= -D[r][s];
          D[r][s] = 1.0 / D[r][s];
          swap(B[r], N[s]);
     }
     
     bool Simplex(int phase){
          int x = phase == 1? m+1 : m;
          while(true){
               int s = -1;
               for(int j = 0; j <= n; ++j){
                    if(phase == 2 && N[j] == -1)continue;
                    if(s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
               }
               if(D[x][s] >= -EPS) return true;
               int r = -1;
               for(int i = 0; i < m; ++i){
                    if(D[i][s] <= 0) continue;
                    if (r == -1 || D[i][n+1] / D[i][s] < D[r][n+1] / D[r][s] || 
                        D[i][n+1] / D[i][s] == D[r][n+1] / D[r][s] && B[i] < B[r]) r = i;
               }
               if(r == -1) return false;
               Pivot(r,s);
          }
     }
     
     DOUBLE Solve(VD &x){
          int r = 0;
          for(int  i = 1; i < m; i++) if(D[i][n+1] < D[r][n+1]) r = i;
          if(D[r][n+1] <= -EPS){
               Pivot(r,n);
               if(!Simplex(1) || D[m+1][n+1] < -EPS) return -numeric_limits<double>::infinity();
               for(int i = 0; i < m; ++i) if(B[i] == -1){
                    int s = -1;
                    for(int j = 0; j <= n; ++j)
                         if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
                    Pivot(i,s);
               }
          }
          if(!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
          x = VD(n);
          for(int i = 0; i < m; ++i) if(B[i] < n) x[B[i]] = D[i][n+1];
          return D[m][n+1];
     }
};

int main(){
     int n;
     while(cin >> n){
          vector<point> myGoats(n);
          for(int i = 0; i < n; ++i){
               double x,y;
               cin >> x >> y;
               myGoats.push_back(point(x,y));
          }          
          VVD A;
          VD b;
          VD c (n,1);
          for(int i = 0; i < n; ++i){
               for(int j = i + 1; j < n; ++j){
                    vector<double> tmp (2);
                    tmp[0] = 1; tmp[1] = 1;
                    b.push_back(myGoats[i].dist2point(myGoats[j]));
                    A.push_back(tmp);
               }
          }
          VD x(n,1);
          LPSolver mySolver = LPSolver(A, b, c);
          printf("%.2f\n", mySolver.Solve(x));
     }
     return 0;
}

