# include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    vector< lli > mio(26);
    for(int i = 0; i < 26; ++i)
        cin >> mio[i];

    string trompirojo;
    cin >> trompirojo;
    map< pair<char, lli> , lli > memo;
    lli sum = 0;
    lli ans = 0;
    for(int i = 0; i < trompirojo.size(); ++i){
        char tmp = trompirojo[i];
        lli sum_tmp = sum;
        sum += mio[tmp - 'a'];
        pair< char, lli > mpair = make_pair(tmp, sum_tmp);
        ans += memo[mpair];
        mpair = make_pair(tmp, sum);
        memo[mpair]++;
    }
    cout << ans << endl;
    return 0;
}
