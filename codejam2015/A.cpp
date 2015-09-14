# include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; ++t){
        int n; cin >> n;
        vector<int> mio(n+1);
        for(int i = 0; i < n + 1; ++i)
            cin >> mio[i];

        int llevo = 0;
        int pongo = 0;
        for(int i = 0; i < mio.size(); ++i){
            if(llevo < i){
                pongo += i - llevo;
                llevo += pongo;
            }
            else
                llevo += mio[i];
        }
        cout << "Case #" << t << ": " << pongo <<endl;
    }
    return 0;
}
