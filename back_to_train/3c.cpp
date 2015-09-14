# include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> mio(3);
    for(int i = 0; i < 3; ++i){
        string tmp; cin >> tmp;
        mio[i] = tmp;
    }
    int xx = 0;
    int oo = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(mio[i][j] == 'X')
                xx++;
            else if(mio[i][j] == '0')
                oo++;
        }
    }
    if(xx + oo == 0){
        cout << "first" << endl;
        return 0;
    }
    if(xx - oo > 1 || oo > xx){
        cout << "illegal" << endl;
        return 0;
    }
    int winnerx = 0;
    int winnero = 0;
    for(int i = 0; i < 3; ++i){
        if(mio[i][0] == mio[i][1] && mio[i][1] == mio[i][2]){
            //cout<<"lleve"<<endl;
            if(mio[i][0] == 'X')
                winnerx++;
            else if(mio[i][0] == '0')
                winnero++;
        }
    }
    for(int i = 0; i < 3; ++i){
        if(mio[0][i] == mio[1][i] && mio[1][i] == mio[2][i]){
            //cout<<"lleve"<<endl;
            if(mio[0][i] == 'X')
                winnerx++;
            else if(mio[i][0] == '0')
                winnero++;
        }
    }
    if(mio[0][0] == mio[1][1] && mio[1][1] == mio[2][2]){
        //cout<<"lleve"<<endl;
        if(mio[0][0] == 'X')
            winnerx++;
        else if(mio[0][0] == '0')
            winnero++;
    }
    if(mio[0][2] == mio[1][1] && mio[1][1] == mio[2][0]){
        //cout<<"lleve"<<endl;
        if(mio[0][2] == 'X')
            winnerx++;
        else if(mio[0][2] == '0')
            winnero++;
    }
    //cout << winnerx << " " << winnero << endl;
    if(winnerx + winnero){
        if(winnerx + winnero > 1){
            cout << "illegal" << endl;
            return 0;
        }
        else if(winnerx == 1){
            if(xx - oo == 1){
                cout << "the first player won" << endl;
                return 0;
            }
            else{
                cout << "illegal" << endl;
                return 0;
            }
        }
        else{
            if(xx - oo == 0){
                cout << "the second player won" << endl;
                return 0;
            }
            else{
                cout << "illegal" << endl;
                return 0;
            }
        }
    }
    else{
        if(oo + xx == 9){
            cout << "draw" << endl;
            return 0;
        }
    }
    if(xx > oo)
        cout << "second" << endl;
    else
        cout << "first" << endl;
    return 0;
}
