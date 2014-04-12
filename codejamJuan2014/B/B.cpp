# include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
const double INF = 1000000.0;

double intercept(double yy, double bb, double mm){
    return (yy - bb)/mm;
}

int main(){
    int T; cin >> T;
    int cont = 0;
    while(T--){
        double c, f, x;
        cin >> c >> f >> x;
        if(x - c < EPS){
            printf("Case #%d: %.7lf\n", ++cont, x/2.0);
        }
        else{
            double t_max = x/2.0;
            double t_eval = INF;
            double new_rate = 2.0;
            double new_b = 0.0;
            double t_new = 0.0;
            while(t_new < t_max){
                double t_new_new = intercept(c, new_b, new_rate);
                t_new = t_new_new;
                new_rate += f;
                new_b = (-1.0)*new_rate*t_new_new;
                t_eval = intercept(x, new_b, new_rate);
                //cout<<t_new<<" "<<t_eval<<" "<<t_max<<" "<<endl;
                if(t_eval < t_max)
                    t_max = t_eval;
                
            }
            printf("Case #%d: %.7lf\n", ++cont, t_max);
        }
    }
    return 0;

}
