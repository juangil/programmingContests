# include <bits/stdc++.h>

using namespace std;

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; ++t){
        int n; cin >> n;
        string mio; cin >> mio;
        //cout << mio << endl;
        int llevo = 0;
        int pongo = 0;
        for(int i = 0; i < mio.size(); ++i){
            int tmp = toInt(mio[i]);
            //cout << tmp << " " << llevo + tmp << endl;
            if(llevo < i && tmp > 0){
                pongo += i - llevo;
                //cout << pongo << endl;
                llevo += (pongo + tmp);
            }
            else
                llevo += tmp;
            //cout << pongo << " " << llevo << endl;
        }
        cout << "Case #" << t << ": " << pongo <<endl;
    }
    return 0;
}
