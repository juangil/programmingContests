# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <math.h>
# include <map>
# include <vector>
# include <set>

using namespace std;

const double EPS = 1e-6;

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

int main(){
	int T; cin >> T;
	for(int t = 0; t < T; ++t){
		int n; cin >> n;
		vector<PT> mio(n);
		for(int i = 0; i < n; ++i){
			int x,y; cin >> x >> y;
			PT tmp = PT(x,y);
			mio[i] = tmp;
		}
		map< pair<PT,double>, int > mmap;
		map< pair<PT,PT>, int > visited;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			PT a = mio[i];
			for(int j = i + 1; j < n; ++j){
				PT b = mio[j];
				double mdist = dist2(a,b);
				//pair<PT,PT> vist = make_pair(a,b);
				//if(visited[vist] == 1)
				//	continue;
				//visited[vist] = 1;
				pair<PT,double> tmp_pair1 = make_pair(a,mdist);
				pair<PT,double> tmp_pair2 = make_pair(b,mdist);
				ans += mmap[tmp_pair1] + mmap[tmp_pair2];
				mmap[tmp_pair1] = 1;
				mmap[tmp_pair2] = 1;
			}
		}
		cout << "Case #" << t + 1 << ": " << ans << endl; 
	}
	return 0;
}