# include <bits/stdc++.h>

using namespace std;
typedef long long int  lli;
typedef unsigned long long int ull;
lli a, b, n, l, t, m, tmp;

lli h(lli i){
  return a + (i - 1LL)*b;
}

bool msum(lli l, lli r){
  if(h(r) > t) return false;
  /*lli tmp1 = (r - l + 1LL)*a;
  lli tmp2 = (r % 2LL == 0LL)? ((r/2LL)*(r - 1LL)):(r*((r - 1LL)/2LL));
  lli tmp3 = (l % 2LL == 0LL)? (((l - 2LL)/2LL)*(l - 1LL)):(((l - 1LL)/2LL)*(l - 2LL));
  lli ret = tmp1 + b*(tmp2 - tmp3);*/
  lli tmp1 = (r - l + 1LL) * a;
  lli tmp2 = (r*(r - 1LL)) / 2LL;
  lli tmp3 = ((l - 2LL)*(l - 1LL)) / 2LL;
  lli ret = tmp1 + b*(tmp2 - tmp3);
  tmp = ret;
  return (ret <= m*t);
}

/*bool get(long long x, long long y){
  if(h(x) > t) return false;
  x--;
  y--;
  long long sum = (y * (y - 1) - x * (x - 1)) / 2;
  return (a * (y - x) + sum * b) <= m*t;
}*/

int main(){
  cin >> a >> b >> n;
  while(n--){
    cin >> l >> t >> m;
    //cout << n << endl;
    if(h(l) > t){
      cout << -1 << endl;
      continue;
    }
    lli i = l;
    /*while(true){
      cout << i << " " << msum(l,i) << " maxt " << t << endl;
      if(msum(l,i) > t*m || i >= 173792) break;
      i++;
    }*/
    lli lo = l;
    lli hi = l + max(t,m) + 10;
    while(lo < hi){
      lli mid = (lo + hi)/2;
      if(msum(l, mid))
        lo = mid;
      else
        hi = mid;
      if(lo + 1LL == hi){
        if(msum(l,hi))
          lo = hi;
        else
          hi = lo;
      }
    }
    cout << lo << endl;
  }
  return 0;
}
