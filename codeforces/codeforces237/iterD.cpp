# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

const int MAXN = 1000001;
int N;
const ulli MOD = 1000000007;

char a[MAXN];
ulli dp[MAXN][34];

int mySymbol(char b){
    if(b == '*') return 3;
    if(b == '1') return 1;
    if(b == '2') return 2;
    if(b == '0') return 0;
    return -10;
}

bool contain(int &a, vector<int> &b){
    for(int i = 0; i < b.size(); ++i)
        if(b[i] == a) return true;
    return false;
}

int main(){

    scanf("%s", &a);
    N = strlen(a);
    //cout<<strlen(a)<<endl;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < 34; ++j)
                dp[i][j] = 0;

    if(strlen(a) == 1){
        if(a[0] == '2' || a[0] == '1') cout<<0<<endl;
        else cout<<((a[0] == '?')? 2:1)<<endl;
        return 0;;
    }

    vector<int> l1; vector<int> l2; vector<int> l3;
    l1.push_back(1);l1.push_back(0);
    l2.push_back(3);
    l3.push_back(3);l3.push_back(2);l3.push_back(1);

    map< int, vector<int> > my_map;
    my_map[0]=(l1);
    my_map[1]=(l2);
    my_map[10]=(l1);
    my_map[11]=(l2);
    my_map[13]=(l3);
    my_map[32]=(l2);
    my_map[23]=(l3);
    my_map[33]=(l3);
    my_map[31]=(l1);
    
    int actual, ant;
    int op [] = {0, 1, 10, 11, 13, 23, 31, 32, 33};
    dp[strlen(a)][0] = 1;
    dp[strlen(a)][10] = 1;
    dp[strlen(a)][31] = 1;
    dp[strlen(a)][33] = 1;
    dp[strlen(a)][13] = 1;
    dp[strlen(a)][23] = 1;
    for(int i = strlen(a) - 1; i >= 0; --i){
        actual = mySymbol(a[i]);
        for(int j = 0; j < 9; ++j){
            int anterior = op[j];
            vector<int> possible = my_map[anterior];
            int ret = 0;
            ant = anterior%10;
            //cout<<i<<" "<<actual<<" "<<anterior<<endl;
            if(actual < 0){
                for(int k = 0; k < possible.size(); ++k){
                    //cout<<"..."<<actual<<" "<<ant<<" "<<possible[k]<<endl;
                    ret = (ret + dp[i+1][(ant*10) + possible[k]])%MOD;
                }
            }
            else if(contain(actual, possible))
                ret = (ret + dp[i+1][(ant*10) + actual])%MOD;
            dp[i][anterior] = ret;
        }
    }

    int ans = (dp[0][0] + dp[0][1] )%MOD;

    cout<<ans<<endl;
    
    return 0;
}