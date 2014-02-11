# include <bits/stdc++.h>

using namespace std;

const int MAX_TREES = 2001;
const int MAX_HEIGHT = 2001;

int my_tree [MAX_TREES][MAX_TREES];
int dp[MAX_HEIGHT];

int main(){
    int c; cin >> c;
    while(c--){
        int t,h,f;
        cin >> t >> h >> f;

        for(int i = 0; i < t; ++i){
            for(int j = 0; j < h; ++j)
                my_tree[i][j] = 0;
        }
        
        for(int i = 0; i < h; ++i) dp[i] = -1;
        
        for(int i = 0; i < t; ++i){
            int a; cin >> a;
            for(int j = 0; j < a; ++j){
                int b; cin >> b;
                my_tree[i][b - 1] += 1;
            }
        }
        
        for(int i = 0; i < t; ++i)
            dp[h - 1] = max(dp[h - 1], my_tree[i][h - 1]);
            
        for(int height = h - 2; height >= 0; height--){
            for(int tree = 0; tree < t; ++tree){
                my_tree[tree][height] += max(my_tree[tree][height+1], (height + f < h)? dp[height + f]:0);
                dp[height] = max(dp[height], my_tree[tree][height]);
            }
        }
        cout<<dp[0]<<endl;
    }
    cin >> c;
    return 0;
}


