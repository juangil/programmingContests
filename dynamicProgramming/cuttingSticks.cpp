# include <bits/stdc++.h>

using namespace std;

const int MAXCUTS = 52;

int myCuts[MAXCUTS];
int dp[MAXCUTS][MAXCUTS];


int cut(int ini, int ending){
    if(dp[ini][ending] != -1) return dp[ini][ending];
    if(ini + 1 ==  ending) return dp[ini][ending] = 0;
    
    int ans = 1 << 30;
    for(int i = ini + 1; i < ending; ++i)
        ans = min(ans, cut(ini, i) + cut(i, ending) + (myCuts[ending] - myCuts[ini]));

    dp[ini][ending] = ans;
    return ans;
}

int main(){
    int l;
    while(cin >> l && l != 0){
        int n;cin >> n;
        n += 2;
        myCuts[0] = 0;
        myCuts[n-1] = l;
        for(int i = 1; i < n-1; ++i)
            cin >> myCuts[i];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dp[i][j] = -1;

        cout<<"The minimum cutting is "<<cut(0,n-1)<<"."<<endl;
    }
    return 0;
}
