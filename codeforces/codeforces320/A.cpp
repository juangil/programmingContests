# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool ispow2(int a){
    if(a == 1) return true;
    int ret = 1;
    while(ret < a){
        ret = 2*ret;
        if(ret == a) return true;
        if(ret > a) return false;
    }
}

int solve(int a){
    if(ispow2(a)) return 1;
    if(a == 0) return 0;
    int ans = 0;
    int tmp = 1;
    int ant = tmp;
    while(tmp < a){
        ant = tmp;
        tmp = tmp*2;
        if(tmp > a){
            ans = 1 + solve(a - ant);
            return ans;
        }
    }
}

int main(){
    lli n;
    while(cin >> n){
        cout << solve(n) << endl;
    }
    return 0;
}
