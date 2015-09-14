# include <bits/stdc++.h>

using namespace std;

int main(){
    string mio;
    cin >> mio;
    int consecutive = 1;
    int ant = mio[0] - '0';
    for(int i = 1; i < mio.size(); ++i){
        int tmp = mio[i] - '0';
        if(tmp ==  ant)
            consecutive++;
        else{
            consecutive = 1;
            ant = tmp;
        }
        if(consecutive >= 7){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return  0;
}
