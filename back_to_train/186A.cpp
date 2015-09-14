# include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cin >> a;
    cin >> b;
    int cont_dif = 0;
    vector< pair<char,char> > mio;
    set<char> mset;
    if(a.size() != b.size()){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < a.size(); ++i){
        mset.insert(a[i]);
        if(a[i] != b[i]){
            cont_dif++;
            pair<char,char> tmp = make_pair(a[i], b[i]);
            mio.push_back(tmp);
        }
    }
    if(cont_dif == 0){
        if(mset.size() == a.size())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return 0;
    }
    if(mio.size() == 2){
        if((mio[0].first == mio[1].second) && (mio[1].first == mio[0].second))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
