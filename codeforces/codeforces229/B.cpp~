# include<bits/stdc++.h>

using namespace std;

long long int a [100050];
long long int b [100050];

int main(){
    int n;
    
    while(cin >> n){
        
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];
        
        long long int joy = 0;
        for(int i = 0; i < n; ++i){
            if(b[i] == 1){
                joy--;
                continue;
            }
            if(2*a[i] >= b[i]){
                int tmp = b[i]/2;
                long long int x = tmp;
                long long int y = b[i] - tmp;
                //if(x <= a[i] && y <= a[i] && x && y)
                joy += x*y;
                //else joy--;
            }
            else joy--;
        } 
        cout<<joy<<endl;
    }

    return 0;
}
