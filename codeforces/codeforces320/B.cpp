# include <bits/stdc++.h>

using namespace std;


bool mycmp(pair< int, pair<int,int> > a, pair< int, pair<int,int> > b){
    return a.first < b.first;
}

int main(){
    int n;
    while(cin >> n){
        vector< pair<int, pair<int,int> > > highest;
        for(int i = 2; i <= 2*n; ++i){
            int m = i - 1;
            for(int j = 1; j <= m; ++j){
                int tmp; cin >> tmp;
                pair< int,int > mpair = make_pair(i,j);
                pair< int, pair<int,int> > emp = make_pair(tmp, mpair);
                highest.push_back(emp);
            }
            //cout << "que paso" << endl;
        }
        sort(highest.begin(), highest.end(), mycmp);
        set< int > rep;
        vector< int > ans((2*n) + 1, 0);
        while(!highest.empty()){
            pair< int, pair<int,int> > take = highest.back();
            //cout << take.first << endl;
            highest.pop_back();
            int a = take.second.first;
            int b = take.second.second;
            //cout << a << " " << b << endl;
            if(rep.count(a) == 0 && rep.count(b) == 0){
                rep.insert(a);
                rep.insert(b);
                //cout << "     meto: " << a << " " << b << " con: " << take.first << endl;
                ans[a] = b;
                ans[b] = a;
            }
        }
        for(int i = 1; i <= 2*n; ++i)
            cout << ans[i] << " ";
    }
    return 0;
}
