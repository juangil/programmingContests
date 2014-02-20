# include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    double W[n][n];
    for(int i = 0; i <n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> W[i][j];
    
    double tmp [n][n];
    for(int i = 0; i <n; ++i)
        for(int j = 0; j < n; ++j)
            tmp[j][i] = W[i][j];
    
    double A [n][n];
    for(int i = 0; i <n; ++i)
        for(int j = 0; j < n; ++j)
            A[i][j] = (tmp[i][j]/2.0) + (W[i][j]/2.0);
           
    double B [n][n] ;
    for(int i = 0; i <n; ++i)
        for(int j = 0; j < n; ++j)
            B[i][j] = (W[i][j]/2.0) - (tmp[i][j]/2.0);
    
    for(int i = 0; i <n; ++i){
        for(int j = 0; j < n; ++j)
            printf("%.8lf ",A[i][j]);
        cout<<endl;
    }
    
    for(int i = 0; i <n; ++i){
        for(int j = 0; j < n; ++j)
            printf("%.8lf ",B[i][j]);
        cout<<endl;
    }
    return 0;
}
