# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

const int MAXN = 1000001;
int N;
const ulli MOD = 1000000007;

string a;
ulli dp[MAXN][4][4];

int mySymbol(char b){
    if(b == '*') return 3;
    if(b == '1') return 1;
    if(b == '2') return 2;
    if(b == '0') return 0;
}

bool valid(int actual, int anterior, int anterior_ant, bool flag = false){
    if(flag){
        if(anterior == 1 && anterior_ant != 3) return false;
        if(anterior == 2) return false;
        return true;
    }
    if(actual == 2 && anterior != 3) return false;
    if(actual == 3 && anterior == 0) return false;
    if(actual == 3 && anterior == 1 && anterior_ant == 3) return false;
    if(actual == 0 && anterior == 3) return false;
    if(actual == 0 && anterior == 1 && anterior_ant == 0) return false;
    if(actual == 0 && anterior == 2) return false;
    
    return true;
}

ulli solve(int i, int ant, int ant_ant){
    //cout<<i<<" "<<ant<<" "<<ant_ant<<endl;
    if(i == N){
        if(!valid(i, ant, ant_ant, true)) return 0;
        return 1;
    }
    if(dp[i][ant][ant_ant] != -1) return dp[i][ant][ant_ant];
    ulli ans = 0;
    if(a[i] != '?'){
        if(!valid(mySymbol(a[i]), ant, ant_ant) && i > 0)return 0;
        ans += solve(i+1, mySymbol(a[i]), ant)%MOD;
    }
    else{
        if(i == 0)
            ans += solve(i+1, 3, ant)%MOD;
        if(ant == 2)
            ans += solve(i+1, 3, 2)%MOD;
        if(ant == 3)
            ans += solve(i+1, 1, 3)%MOD + ((i < N - 1)? solve(i+1, 2, 3):0)%MOD + solve(i+1, 3, 3)%MOD;
        if(ant == 0)
            ans += solve(i+1, 0, 0)%MOD + solve(i+1, 1, 0)%MOD;
        if(ant == 1){
            if(ant_ant == 3)
                ans += solve(i+1, 1, 1)%MOD + solve(i+1, 0, 1)%MOD;
            if(ant_ant == 1 || ant_ant == 0)
                ans += solve(i+1, 3, 1)%MOD;
        }
    }
    return dp[i][ant][ant_ant] = ans;
}

int main(){
    while(cin >> a){
        N = a.size();
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 4; ++k)
                    dp[i][j][k] = -1;
        
        if(a.size() == 1){
            cout<<((a[0] == '?')? 2:0)<<endl;
            continue;
        }
        
        ulli ans = solve(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
