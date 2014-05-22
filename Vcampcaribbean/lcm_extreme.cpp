# include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 1000000;
lli mod = 123457;
int my_phi[MAXN];
bool primes [MAXN];
lli div_sum [MAXN];
lli my_sum[MAXN];
lli ii [MAXN];
lli inverse = 61729;


lli phi(int n){
	if (n == 1)
        return 1ll;
    lli out = n;
    // 2
    if (n % 2 == 0) {
        out -= out / 2;
        do
            n /= 2;
        while (n % 2 == 0);
    }
    // odds
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) {
            out -= out / i;
            do
                n /= i;
            while (n % i == 0);
        }
    //
    if (n > 1)
        out -= out / n;
    return out;
}



int main(){
	for(int i = 1; i <= MAXN; ++i)
		my_phi[i] = phi(i);
	//gen_primes();
	for(int i = 0; i <= MAXN; ++i)
		div_sum[i] = 0;
		
	for(int i = 1; i <= MAXN; ++i){
		for(int j = i; j <= MAXN; j += i)
			div_sum[j] += ((i%mod)*(my_phi[i]%mod))%mod;
	}

	for(int j = 1; j <= MAXN; ++j)
		my_sum[j] = ((((j%mod)*((1 + div_sum[j])%mod))%mod)*(inverse))%mod;
		

	ii[1] = 1; 
	for(int i = 2; i <= MAXN; ++i)
		ii[i] = (ii[i-1]%mod + my_sum[i]%mod)%mod;
	
	int n;
	while(scanf("%d", &n) != EOF){
		lli ans = ii[n];
		printf("%lld\n", ans);
	}
	return 0;
}
