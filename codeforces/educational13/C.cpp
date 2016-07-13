# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>


using namespace std;
typedef long long int lli;

lli gcd ( lli a, lli b )
{
  lli c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

lli lcm(lli a, lli b){
	return (a/gcd(a,b))*b;
}

int main(){
	lli n,a,b,p,q;
	cin >> n >> a >> b >> p >> q;
	lli mred = n/a;
	lli mblue = n/b;
	lli mlcm = n / lcm(a,b);
	lli ans = (p > q)? ((mred*p) + (mblue*q) - (mlcm*q)):((mred*p) + (mblue*q) - (mlcm*p));
	cout << ans << endl;
	return 0;
}