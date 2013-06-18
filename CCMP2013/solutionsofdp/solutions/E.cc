#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000003

struct Point {
  long long x, y;
  Point(long long x = 0, long long y = 0) : x(x), y(y) {}
  Point operator*(long long c) {return Point(c*x, c*y);}
  Point operator+(const Point& p) {return Point(x+p.x, y+p.y);}
  Point operator-(const Point& p) {return Point(x-p.x, y-p.y);}
};

long long cp(const Point& a, const Point& b) {
  return a.x*b.y - a.y*b.x;
}

bool pcmp(const Point& a, const Point& b) {
  bool aup = (a.y > 0 || a.y == 0 && a.x > 0);
  bool bup = (b.y > 0 || b.y == 0 && b.x > 0);
  if (aup != bup) return aup;
  return cp(a, b) > 0;
}

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    vector<Point> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;

    // Count sum of triangle areas
    long long tsum = 0;
    // Count sum of (triangle area) * (# of points in triangle)
    long long tprod = 0;
    if (N >= 4) for (int ci = 0; ci < N; ci++) {
      vector<Point> v;
      for (int i = 0; i < N; i++) if (i != ci) v.push_back(P[i] - P[ci]);
      sort(v.begin(), v.end(), pcmp);
      for (int i = 0; i < N-1; i++) v.push_back(v[i]);
      vector<Point> vcum(1);
      for (int i = 0; i < v.size(); i++) vcum.push_back(vcum.back() + v[i]);

      // Last vector on left of v[i]
      int Li = 0;
      // First vector on right of v[i]
      int Ri = 1;
      // Sum of (vector on left of v[i]) * (# of convex vectors on right)
      Point Lsum(0, 0);
      // Sum of (vector on right of v[i]) * (# of convex vectors on left)
      Point Rsum(0, 0);
      // Sum of (vector on right of v[i]) x (sum of convex vectors on left)
      long long LRprod = 0;
      while (Li+1 < N-1 && cp(v[0], v[Li+1]) > 0) {
        Li++; Ri++;
      }
      for (int i = 1, iopp = Ri; i <= Li; i++) {
        while (iopp < N-1 && cp(v[i], v[iopp]) > 0) iopp++;
        Lsum = Lsum + v[i] * (iopp-Ri);
        Rsum = Rsum + (vcum[iopp] - vcum[Ri]);
        LRprod = (LRprod + cp(v[i], vcum[iopp] - vcum[Ri])) % MOD;
      }

      // Sweep i around, updating Lsum, Rsum, and LRprod as we go.
      for (int i = 0;;) {
        tprod = (tprod + cp(v[i], Lsum)) % MOD;
        tprod = (tprod + cp(Rsum, v[i])) % MOD;
        tprod = (tprod + LRprod) % MOD;
        tsum = (tsum + cp(v[i], vcum[Ri]-vcum[i+1])) % MOD;

#if 0
        // Sanity check
        Point Lsum2, Rsum2;
        long long LRprod2 = 0;
        for (int j = i+1; j < i+N-1; j++) if (cp(v[i], v[j]) > 0)
        for (int k = j+1; k < i+N-1; k++) if (cp(v[k], v[i]) > 0)
        if (cp(v[j], v[k]) > 0) {
          Lsum2 = Lsum2 + v[j];
          Rsum2 = Rsum2 + v[k];
          LRprod2 = (LRprod2 + cp(v[j], v[k])) % MOD;
        }
        assert(Lsum.x == Lsum2.x);
        assert(Lsum.y == Lsum2.y);
        assert(Rsum.x == Rsum2.x);
        assert(Rsum.y == Rsum2.y);
        assert((LRprod-LRprod2) % MOD == 0);
#endif

        if (++i == N-1) break;

        while (Ri < i+N-1 && cp(v[i], v[Ri]) >= 0) {
          Ri++;
        }
        for (int j = Li+1; j < Ri; j++) {
          // Remove v[j] from R.
          Lsum = Lsum - (vcum[Li+1]-vcum[i]);
          Rsum = Rsum - v[j] * (Li+1-i);
          LRprod = (LRprod - cp(vcum[Li+1]-vcum[i], v[j])) % MOD;
          // Add v[j] to L.
          Lsum = Lsum + v[j] * (i+N-1-Ri);
          Rsum = Rsum + (vcum[i+N-1]-vcum[Ri]);
          LRprod = (LRprod + cp(v[j], vcum[i+N-1]-vcum[Ri])) % MOD;
        }
        Li = Ri-1;
      }
    }
    while (tprod % 3) tprod += MOD;
    tprod /= 3;
    while (tsum % 3) tsum += MOD;
    tsum /= 3;

    long long ret = tsum * (N-3) + tprod * 2;
    while (ret % 2) ret += MOD;
    ret /= 2;
    cout << "Case " << prob++ << ": " << (ret % MOD + MOD) % MOD << endl;
  }
}
