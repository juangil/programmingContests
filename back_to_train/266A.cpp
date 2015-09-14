# include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string mio; cin >> mio;
    char current = mio[0];
    int todel = 0;
    for(int i = 1; i < n; ++i){
        char tmp = mio[i];
        if(current == tmp)
            todel++;
        else
            current = tmp;
    }
    int ans = (n == 1)? 0:todel;
    cout << ans << endl;
    return 0;
}
