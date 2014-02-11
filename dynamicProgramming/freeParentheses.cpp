# include <bits/stdc++.h>
# define D(x) cout<<(x)<<endl;
using namespace std;

const int MAXVALUES = 7001;
const int MAXNUMS = 32;

int used [MAXVALUES];
bool dp[MAXNUMS][MAXNUMS][MAXVALUES];
int sig[MAXNUMS];
int num[MAXNUMS];
int N;

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

void solve(int idx, int open, int val){
    //cout<<(dp[idx][open][val + 3500] == 0)<<endl;
    if(dp[idx][open][val + 3500]) return;
    dp[idx][open][val + 3500] = 1;
    if(idx == N){
        //cout<<"pass"<<endl;
        used[val + 3500] = 1;
        return;
    }
    int new_val = val + num[idx]*sig[idx]*((open%2)? -1:1);
    if(sig[idx] == -1)
        solve(idx+1, open+1, new_val);
    if(open > 0)
        solve(idx+1, open-1, new_val);
    solve(idx+1, open, new_val);
}


int main(){
    string expr;
    while(getline(cin, expr)){
        stringstream ss(expr);
        string mio;
        int i = 0;
        int j = 0;
        int tmp;
        while(ss>>mio) {
            if(mio != "+" && mio != "-"){
                tmp = toInt(mio);
                num[i] = tmp*((i == 0)? 1:sig[i-1]);
                i++;
            }
            else{
                if(mio == "-") sig[j] = -1;
                else sig[j] = 1;
                j++;
            }
        }
        int totalplus = num[0];
        for(int k = 0; k < i; ++k)
            totalplus += num[k];
        
        totalplus += 3500;
        
        for(int k = 0; k < totalplus; ++k)
            used[k] = 0;
        
        for(int k = 0; k < i; ++k)
            for(int m = 0; m < i; ++m)
                for(int l = 0; l < MAXVALUES; ++l)    
                    dp[k][m][l] = false;

        
        N = i;
        solve(0,0,0);
        int cont = 0;
        for(int k = 0; k <= totalplus; ++k)    
            cont += used[k];
        
        cout<<cont<<endl;
    }


}


