using namespace std;
#include<iostream>
#include<string>
#include<cassert>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define For(i,n) for(int i = 0 ; i<(n) ; ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define init(x) memset(x, 0, sizeof(x))
template<class T>
int to_int(T r){stringstream ss; ss<<r; int k; ss>>k; return k;}

bool my_cmp(string a, string b){
    int i = a[0] - 'A';
    int j = to_int(a.substr(1)) -1;
    int k = b[0] - 'A';
    int l = to_int(b.substr(1)) -1;
    return j < l;
    return i < k;
}

int main(){
    int m,n;
    while(cin>>m>>n and m+n){
        int silla[m+10][n+10];init(silla);
        int llega[m+10][n+1]; init(llega);
        int puestos;cin>>puestos;
        while(puestos--){
            string nombre; cin>>nombre;
            char tales; cin>>tales;
            int i = nombre[0] - 'A';
            int j = to_int(nombre.substr(1)) -1;
            if(tales == '-')
                silla[i][j] =  1;
            else
                silla[i][j+1] =  1;
        }
        int queries;cin>>queries;
        int paila = 0;
        For(kk,queries){
            string name;cin>>name;
            int i = name[0] - 'A';
            int j = to_int(name.substr(1)) -1;
            llega[i][j] = 1;
        }
        For(i,m){
            For(j,n){
                if(llega[i][j]){
                    if(!silla[i][j]) silla[i][j] = 1;
                    else if(!silla[i][j+1]) silla[i][j+1] = 1;
                    else{
                         paila = 1;
                         break;
                   }
                    
                }
            }
        }
        if(paila)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
