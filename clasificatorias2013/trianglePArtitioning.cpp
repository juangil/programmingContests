# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

using namespace std;

# define EPS 1e-7

bool mycmp (double a, double b){return  (a < b);}

bool cmp3 (const vector<double> &t1,const vector<double> &t2){
     if(fabs((t1[0]/t2[0]) - (t1[1]/t2[1])) < EPS && fabs((t1[1]/t2[1]) - (t1[2]/t2[2])) < EPS && fabs((t1[0]/t2[0]) - (t1[2]/t2[2])) < EPS) return true;
     else return false;
}

vector< vector<double> > ans;

void divideTriangles(vector<double> v){
     vector< vector<double> > tmp(2, vector<double> (3));
     ans.push_back(v);
     vector<double> newTriangle1 (3);
     vector<double> newTriangle2 (3);
     //first triangle
     newTriangle1[0] = v[2]/2.0;
     newTriangle1[1] = sqrt(2*(v[1]*v[1]) + 2*(v[0]*v[0]) - (v[2]*v[2]))/2.0;
     newTriangle1[2] = v[1];
     //second triangle
     newTriangle2[0] = v[2]/2.0;
     newTriangle2[1] = newTriangle1[1];
     newTriangle2[2] = v[0];
     //sorting triangles
     sort(newTriangle1.begin(),newTriangle1.end(),mycmp);
     sort(newTriangle2.begin(),newTriangle2.end(),mycmp);
     tmp[0] = newTriangle1;
     tmp[1] = newTriangle2;
     //cout<<"triangle 1: "<<newTriangle1[0]<<" "<<newTriangle1[1]<<" "<<newTriangle1[2]<<endl;
     //cout<<"triangle 2: "<<newTriangle2[0]<<" "<<newTriangle2[1]<<" "<<newTriangle2[2]<<endl;
     for(int i = 0; i < 2; ++i){
          int cont = 0;
          for(int j = 0; j < ans.size(); ++j)
               if(!cmp3(tmp[i], ans[j])) cont++;
          if(cont == ans.size()){
               ans.push_back(tmp[i]);
               divideTriangles(tmp[i]);
          }
      }               
}

int main(){
     int n;cin >> n;
     for(int i = 0; i < n; ++i){
          double a,b,c;
          ans.clear();
          vector<double> myTriangle(3);
          cin >> myTriangle[0] >> myTriangle[1] >> myTriangle[2];
          sort(myTriangle.begin(),myTriangle.end(),mycmp);
          ans.push_back(myTriangle);
          divideTriangles(myTriangle);
          cout<<ans.size()/2<<endl;
     }
     return 0;
}
