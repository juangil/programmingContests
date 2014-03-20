# include <bits/stdc++.h>

using namespace std;

bool diagonal(int x, int y, int n){
    int i = 0, j = n - 1;
    while(j >= 0 && i <= n - 1){
        if(x == i && y == j) return true;
        i++; j --;
    } 
    return false;
}

int main(){
    int n;
    cin >> n;
    char mylet[n][n];
    vector<char> nodiag;
    char diag1 [n];
    char diag2 [n];
    for(int i = 0; i <n; ++i)
        scanf("%s", &mylet[i]);
        
    
    for(int i = 0; i < n; ++i){
        for(int  j = 0; j < n; ++j){
            if(i == j)
                diag1[i] = mylet[i][j];
            else if(!diagonal(i,j,n))
                nodiag.push_back(mylet[i][j]);
        }
    }
    
    int i = 0, j = n - 1;
    while(j >= 0 && i <= n - 1){
        diag2[i] = mylet[i][j];
        i++; j --;
    }
    //for( i = 0; i < n; ++i)cout<<diag1[i]<<endl;
    bool flag1 = true;
    char mio = diag1[0];
    for( i = 0; i < n; ++i){
        if(diag1[i] != mio || diag2[i] != mio){
            flag1 = false;
            break;
        }
    }
    if(flag1){
        mio = nodiag[0]; char mio2 = diag1[0];
        for(i = 0; i < nodiag.size(); ++i){
            if(nodiag[i] != mio || nodiag[i] == mio2){
                flag1 = false;
                break;
            }
        }
    }
    if(flag1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
        
    
    return 0;
}
