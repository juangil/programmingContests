# include <bits/stdc++.h>

using namespace std;

int main(){
    vector< string > chess(8);
    for(int i = 0; i < 8; ++i)
        cin >> chess[i];
    for(int i = 0; i < 8; ++i){
        string current = chess[i];
        char tmp = current[0];
        int rep = 0;
        for(int j = 1; j < 8; ++j){
            if(tmp == current[j])
                rep++;
            tmp = current[j];
        }
        if(rep == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    return 0;
}
