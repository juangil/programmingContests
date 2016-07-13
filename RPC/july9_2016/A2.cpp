# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
const double EPS = 1e-6;

double f(vector< pair<double,double> > &mval, double &m, double &mmax){
	double mm = 1e9, mx = 0.0;
	for(int i = 0; i < mval.size(); ++i){
		double mdist = ((mmax - mval[i].first)*mval[i].second) + ((m - mmax)*mval[i].second);
		mm = fmin(mdist, mm);
		mx = fmax(mdist, mx);
	}
	return -1.0*(mx - mm);
}

int main(){ IO
	int n;
	while(cin >> n && n){
		double mmax = 0.0;
		vector< pair<double, double> > mval(n);
		for(int i = 0; i < n; ++i){
			double a,b;
			cin >> a >> b;
			mval.push_back(make_pair(a,b));
			mmax = fmax(a,b);
		}
		double l = 0.0, r = 1e7;
		int iter = 60;
		double target = 0.0;
		while(true){
			if(fabs(l - r) < EPS && iter-- == 0)
				break;

			double m1 = l + ((r - l) / 3.0);
			double m2 = r - ((r - l) / 3.0);
			if(m1 - m2 > EPS)
				break;

			double f1 = f(mval, m1, mmax);
			double f2 = f(mval, m2, mmax);
			if(f1 -  f2 < EPS)
				l = m1;
			else
				r = m2;
		}
		target = (l + r)/2.0;
		double ans = -1.0*f(mval, target, mmax);
		printf("%.3lf\n", ans);

	}
	return 0;
}