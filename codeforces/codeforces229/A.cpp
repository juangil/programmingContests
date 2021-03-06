# include<bits/stdc++.h>

using namespace std;

int myx [101];
int myy [101];

int main(){
    int n;
    
    while(cin >> n){
        for(int i = 0; i <= 100; ++i){
            myx[i] = 0;
            myy[i] = 0;
        }
        pair<int,int> point;
        for(int i = 0; i < n; ++i){
            cin >> point.first >> point.second;
            myx[point.first] += 1;
            myy[point.second] += 1;
        }
        int contx = 0, conty = 0;
        for(int i = 0; i <= 100; ++i)
            if(myx[i]) contx++;
        for(int i = 0; i <= 100; ++i)
            if(myy[i]) conty++;
        
        cout<<min(contx,conty)<<endl;
    
    }
    return 0;
}
