# include <bits/stdc++.h>

using namespace std;

bool myCmp(double a, double b){
    return a < b;
}

bool myCmp2(double a, double b){
    return a > b;
}

int main(){
    int T; cin >> T;
    int cont = 0;
    while(T--){
        int n; cin >> n;
        vector<double> naomi(n);
        vector<double> ken(n);
        for(int i = 0; i < n; ++i)
            cin >> naomi[i];
        for(int i = 0; i < n; ++i)
            cin >> ken[i];
        
        
        sort(naomi.begin(), naomi.end(), myCmp);
        sort(ken.begin(), ken.end(), myCmp);
        vector<double> naomi_d = naomi;
        vector<double> ken_d = ken;
        int war = 0;
        while(!naomi.empty()){
            double actual = naomi[*naomi.begin()];
            std::vector<double>::iterator mio = upper_bound(ken.begin(), ken.end(), actual);
            if(mio == ken.end()){
                naomi.erase(naomi.begin());
                ken.erase(ken.begin() + 0);
                war++;
            }
            else{
                naomi.erase(naomi.begin() + 0);
                ken.erase(mio);
            }
        }
        sort(naomi_d.begin(), naomi_d.end(), myCmp2);
        sort(ken_d.begin(), ken_d.end(), myCmp2);
        
        int d_war = 0;
        while(!naomi_d.empty()){
            double actual = naomi_d[*naomi_d.begin()];
            int mio = ken_d.size();
            /*for(int i = 0; i < naomi_d.size(); ++i)
                cout<<naomi_d[i]<<" ";
            
            cout<<endl;    
            for(int i = 0; i < naomi_d.size(); ++i)
                cout<<ken_d[i]<<" ";
            cout<<endl;    */
            for(int i = 0; i < ken_d.size(); ++i){
                if(actual > ken_d[i]){
                    mio = i;
                    break;
                }
            }
            if(mio == ken_d.size()){
                naomi_d.erase(naomi_d.begin());
                ken_d.erase(ken_d.begin() + 0);
            }
            else{
                naomi_d.erase(naomi_d.begin() + 0);
                ken_d.erase(ken_d.begin() + mio);
                d_war++;
            }
        }
        printf("Case #%d: %d %d\n", ++cont, d_war, war);
    
    }


}
