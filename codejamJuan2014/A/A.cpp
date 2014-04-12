# include  <bits/stdc++.h>

using namespace std;
const int N = 4;
int my_nums[N][N];

int main(){
    int t; cin >> t;
    int cont = 0;
    while(t--){
        int primero; cin >> primero;
        vector<int> super_nums(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int a; cin >> a;
                my_nums[i][j] = a;
                if(i+1 == primero)
                    super_nums[j] = a;
            }
        }
        int segundo; cin >> segundo;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> my_nums[i][j];
            }
        }
        
        int my_actual = 0, apariciones = 0;
        for(int i = 0; i < N; ++i){
            int actual = super_nums[i];
            for(int j = 0; j < N; ++j){
                if(my_nums[segundo - 1][j] == actual){
                    my_actual = actual;
                    apariciones++;
                    break;
                }
            }
        }
        if(apariciones == 1)printf("Case #%d: %d\n", ++cont, my_actual);
        else if(apariciones > 1) printf("Case #%d: Bad magician!\n", ++cont);
        else printf("Case #%d: Volunteer cheated!\n", ++cont);
    }
    return 0;
    
}
