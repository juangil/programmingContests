# include <bits/stdc++.h>

suing namespace std;


int main(){
    double a, d;int n;
    while(cin  >> a >> d >> n){
        long long int dd = (int)d*10000;
        long long int aa = (int)d*10000;
        long long int sumx = 0;
        long long int sumy = 0;
        while(n--){
            if(state == 0){
                sumx += dd;
                if(sumx > aa){
                    sumy = sumx - aa;
                    sumx = aa;
                    printf("%.10lf %.10lf\n", sumx, sumy);
                    state = 1;
                }
                else{
                    printf("%.10lf %.10lf\n", sumx, 0.0);
                }
            }
            else if(state == 1){
                sumy += dd;
                if(sumy > aa){
                    sumx = (sumy - aa);
                    sumx = aa;
                }
                else{
                    printf("%.10lf %.10lf\n", sumx, 0.0);
                }
            }
            else if(state == 2){
                sumx -= dd;
                if(sumx < 0){
                    sumy = sumx - aa;
                    sumx = aa;
                }
                else
                    printf("%.10lf %.10lf\n", sumx, 0.0);
            }
            else if(state == 3){
                sumy -= dd;
                if(sumy < 0){
                    sumy = sumx - aa;
                    sumx = aa;
                }
                else
                    printf("%.10lf %.10lf\n", sumx, 0.0);
            }
            
        
        }
    }
    return 0;
}
