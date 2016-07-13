#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) //cout << #x << " = " << (x) << endl;

const double EPS = 1e-6;

double f (vector<pair<double, double>> &v, double m, vector<double> &superd, double mmax) {
  double mm = INT_MAX, mx = 0;
  D(mmax) D(m)
  for (int i = 0; i < v.size(); ++i) {
    double t = superd[i] + ((m - mmax)*v[i].second);
    //cout << t << endl;
    mm = fmin(t, mm);
    mx = fmax(t, mx);
  }
  D(mm) D(mx)
  return -1*(mx - mm);
}

int main() { IO
  int n;
  while (cin >> n) {
    if (!n) break;

    double mx = -INT_MAX;
    vector< pair<double, double> > v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
      if (v[i].first > mx) mx = v[i].first;
    }
    vector<double> superd(n, 0.0);
    for(int i = 0; i < n; i++){
      superd[i] = (mx - v[i].first)*v[i].second;
      //cout << superd[i] << endl;
    }
    double l = mx, r = 1e8;

    int lim = 60;
    while (fabs(r - l) > EPS && lim --> 0) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if(fabs(m2 - m1) < EPS || m2 < m1)
        break;
      double v1 = f(v, m1, superd, mx);
      double v2 = f(v, m2, superd, mx);
      //cout << v1 << " " << v2 << endl;

      //D(v1) D(v2) cout << endl;
      if (v1 < v2) {
        l = m1;
      }
      else {
        r = m2;
      }
    }

    double ans = f(v, (r + l) / 2, superd, mx);
    cout << fixed << setprecision(3) << ans * -1<< endl;
  }

  return 0;
}
