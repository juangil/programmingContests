# include <bits/stdc++.h>

using namespace std;

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; ++t){
        int d; cin >> d;
        map<int,int, classcomp> mio;
        for(int i = 0; i < d; ++i){
            int a; cin >> a;
            mio[a]++;
        }
        int tiempo_acum = 0;
        int ans = 0;
        int best_so_far = 1 << 30;
        for (std::map<int,int>::iterator it=mio.begin(); it!=mio.end(); ++it){
            //cout << it->first << " " << it->second <<endl;
            int como_todos = tiempo_acum + it->first;
            int nuevo_p1 = it->first/2;
            int nuevo_p2 = it->first - nuevo_p1;
            int tiempo_partiendo = it->second;
            mio[nuevo_p1] += it->second;
            mio[nuevo_p2] += it->second;
            mio.erase (it);
            //cout << tiempo_acum << " " << tiempo_partiendo << " " << mio.begin()->first << endl;
            int divido_como = tiempo_acum + tiempo_partiendo + mio.begin()->first;
            if(divido_como <= como_todos){
                tiempo_acum += tiempo_partiendo;
                ans += tiempo_acum;
                best_so_far = min(ans, best_so_far);
                continue;
            }
            else{
                //cout << ans << " " << como_todos << endl;
                ans = como_todos;
                break;
            }
        }
        cout << "Case #" << t << ": " << ans <<endl;
    }
    return 0;
}
