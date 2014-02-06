# include <bits/stdc++.h>
# define square(x) (x)*(x)
using namespace std;

int N;
const int MAXMATCHINGS = (1 << 16);
const int MAXN = 16;

double dist[MAXN][MAXN];
double dp[MAXMATCHINGS];

double matching(int bit_mask){
    if(dp[bit_mask] > -0.5) return dp[bit_mask];
    if(bit_mask == (1 << 2*N) - 1) return dp[bit_mask] = 0.0;
    
    double ans = (double)(1<<30);
    for(int i = 0; i < 2*N; ++i){
        if(!(bit_mask & (1 << i))){
            for(int j = i + 1; j < 2*N; ++j){
                if(!(bit_mask & (1 << j)))
                    ans = min(ans, dist[i][j] + matching(bit_mask | (1 << i) | (1 << j)));
            }
            break;
        }
        
    }
    return dp[bit_mask] = ans;
}


int main(){
    int n;int tc = 0;
    while(cin >> n && n != 0){
        N = n;
        vector< pair<double,double> > students(2*n);
        for(int i = 0; i < 2*n; ++i){
            string name;double x,y;
            cin >> name >> x >> y;
            students[i] = make_pair(x,y);
        }
        for(int i = 0; i < 2*n; ++i){
            for(int j = 0; j < 2*n; ++j)
                dist[i][j] = sqrt(square(students[i].first - students[j].first) + square(students[i].second - students[j].second));
        }
        for(int i = 0; i < (1<<2*n); ++i)
            dp[i] = -1.0;
        
        printf("Case %d: %.2lf\n", ++tc, matching(0));
    }
    return 0;
}
