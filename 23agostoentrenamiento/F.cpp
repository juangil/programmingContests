using namespace std;
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>

int next_int(){
    int r;cin>>r;return r;
}

int main(){
    int n;
    while(cin>>n and n){
        vector<int> visit(49,0);
        int r;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 6; ++j)
                visit[next_int()-1] = true;
            
        int paila = 0;
        for(int i = 0;i < 49; ++i)
            if(visit[i]==0)paila = 1;
            
        if(paila)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
