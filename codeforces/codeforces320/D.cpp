# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    int n,k;
    lli x;
    cin >> n >> k >> x;

    vector<lli> mnums(n + 2, 0);
    vector<lli> prefor(n + 2, 0);
    vector<lli> sufor(n + 2, 0);

    for(int i = 1; i <= n; ++i)
        cin >> mnums[i];

    lli mul = 1;
    for(int i = 1; i <= k; ++i)
        mul *= x;

    for(int i = 1; i <= n; ++i)
        prefor[i] = mnums[i] | prefor[i - 1];

    for(int i = n; i >= 1; --i)
        sufor[i] = mnums[i] | sufor[i + 1];

    lli ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, prefor[i - 1] | mnums[i] * mul | sufor[i + 1]);

    cout << ans << endl;
    return 0;
}
