# include <bits/stdc++.h>
# define D(x) cout<<(x)<<endl;
using namespace std;

const int MAXVALUES = 7002;
const int MAXNUMS = 32;

bool used [MAXVALUES];
bool dp[MAXNUMS][MAXNUMS][MAXVALUES];
int sig[MAXNUMS];
int num[MAXNUMS];
int N;

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


void solve(int idx, int open, int val){
    if(dp[idx][open][val + 3500]) return;
    dp[idx][open][val + 3500] = 1;
    if(idx == N){
        used[val + 3500] = 1;
        return;
    }
    int new_val = val + num[idx] * sig[idx] * ((open%2)? -1:1);
    
    if(sig[idx] == -1)
        solve(idx+1, open+1, new_val);
    if(open > 0)
        solve(idx+1, open-1, new_val);
    solve(idx+1, open, new_val);
}


int main(){
    string expr;
    while(getline(cin, expr)){
        if(expr.size() <= 1) break;
        stringstream ss(expr);
        string mio;
        int i = 0;
        int j = 1;
        int tmp;
        sig[0] = 1;
        while(ss>>mio) {
            if(mio != "+" && mio != "-"){
                tmp = toInt(mio);
                num[i] = tmp;
                i++;
            }
            else{
                if(mio == "-") sig[j] = -1;
                else sig[j] = 1;
                j++;
            }
        }
        
        for(int k = 0; k <= MAXVALUES; ++k)
            used[k] = 0;
        
        for(int k = 0; k < MAXNUMS; ++k)
            for(int m = 0; m < MAXNUMS; ++m)
                for(int l = 0; l < MAXVALUES; ++l)    
                    dp[k][m][l] = 0;

        N = i;
        solve(0,0,0);
        int cont = 0;
        for(int k = 0; k < MAXVALUES; ++k)
            cont += used[k];
        
        cout<<cont<<endl;
    }
    return 0;


}

