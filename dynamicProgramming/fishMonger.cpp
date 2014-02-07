# include <bits/stdc++.h>

using namespace std;

const int MAXNODES = 50;
const int MAXINT = 1<<30;
const int MAXTIME = 1000;
int T,N;

pair<int,int> dp [MAXNODES][MAXTIME];
int travelTime [MAXNODES][MAXNODES];
int toll [MAXNODES][MAXNODES];

pair<int,int> cost(int currentNode, int timeLeft){
    if(timeLeft < 0) return dp[currentNode][timeLeft] = make_pair(MAXINT, MAXINT);
    if(dp[currentNode][timeLeft].first != -1) return dp[currentNode][timeLeft];
    if(currentNode == N -1) return make_pair(0,0);
    
    pair<int,int> ans = make_pair(MAXINT, MAXINT);
    for(int i = 0; i < N; ++i){
        if(currentNode == i) continue;
        pair<int,int> tmp = cost(i, timeLeft - travelTime[currentNode][i]);
        if(tmp.first + toll[currentNode][timeLeft] < ans.first){
            ans.first = tmp.first + toll[currentNode][timeLeft];
            ans.second = tmp.second + travelTime[currentNode][timeLeft];
        }
    }
    
    return dp[currentNode][timeLeft] = ans;
}


int main(){
    int n, t;
    while(cin >> n >> t && (n+t)){
        N = n; T = t;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> travelTime[i][j];
       
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> toll[i][j];
                
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        pair<int,int> ans = cost(0,t);
        cout<<ans.first<<" "<<T - ans.second<<endl;
    
    }

}
