# include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string mio; cin >> mio;
    int A = 0, F = 0, I = 0;
    for(int i = 0; i < n; ++i){
        if(mio[i] == 'A')
            A++;
        if(mio[i] == 'F')
            F++;
        if(mio[i] == 'I')
            I++;
    }
    int cans = 0;
    for(int i = 0; i < n; ++i){
        if(mio[i] != 'F'){
            if(mio[i] == 'I'){
                if(I == 1)
                    cans++;
            }
            else
                cans += (I == 0);
        }
    }
    cout << cans << endl;
    return 0;
}
