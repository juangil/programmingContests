# include <bits/stdc++.h>

using namespace std;

int mycont(char tmp){
    if(tmp == '.') return 0;
    if(!isupper(tmp)){
        if(tmp == 'q')
            return 9;
        else if(tmp == 'r')
            return 5;
        else if(tmp == 'b')
            return 3;
        else if(tmp == 'n')
            return 3;
        else if(tmp == 'p')
            return 1;
        else if(tmp == 'k')
            return 0;
        return 0;
    }
    else{
        if(tmp == 'Q')
            return 9;
        else if(tmp == 'R')
            return 5;
        else if(tmp == 'B')
            return 3;
        else if(tmp == 'N')
            return 3;
        else if(tmp == 'P')
            return 1;
        else if(tmp == 'K')
            return 0;
        return 0;
    }
}

int main(){
    vector< string > mio(8);
    for(int i = 0; i < 8; ++i){
        string mline;
        cin >> mline;
        mio[i] = mline;
    }
    int wp = 0, bp = 0;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            char tmp = mio[i][j];
            if(isupper(tmp))wp += mycont(tmp);
            else bp += mycont(tmp);
        }
    }
    
    if(bp == wp)
        cout<< "Draw" <<endl;
    else if(wp > bp)
        cout<< "White" <<endl;
    else
        cout<< "Black" <<endl;
    return 0;
}
