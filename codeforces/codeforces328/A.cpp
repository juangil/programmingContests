# include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> mio(8);
    for(int i = 0; i < 8; ++i)
        cin >> mio[i];

    pair<char,int> winner = make_pair('A',10000);
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            char tmp = mio[i][j];
            if(tmp == 'W'){
                bool paila = false;
                for(int k = i - 1; k >= 0; k--){
                    //cout << (mio[k][j] == '.') << endl;
                    if(mio[k][j] != '.')
                        paila = true;
                }
                //cout << paila << endl;
                if(!paila){
                    if(winner.second >= i){
                        winner.second = i;
                        winner.first = 'A';
                    }
                }
            }
            if(tmp == 'B'){
                bool paila = false;
                for(int k = i + 1; k < 8; k++){
                    if(mio[k][j] != '.')
                        paila = true;
                }
                if(!paila){
                    int dist = 7 - i;
                    if(winner.second > dist){
                        winner.second = dist;
                        winner.first = 'B';
                    }
                }
            }
        }
    }
    cout << winner.first<< endl;
    //cout << winner.second << endl;
    return 0;
}
