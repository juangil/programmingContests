# include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        int total = 0;
        if(n < m){
            int parejasnb = m/2;
            int res = m - parejasnb;
            int equipos = (parejasnb < n)? parejasnb:n;
            int sobranb = m - equipos*2;
            int sobraxp = n - equipos;
            //cout<<equipos<<" "<<parejasnb<<" "<<sobranb<<" "<<sobraxp<<endl;
            total = equipos;
            if(sobraxp > 0){
                while(sobraxp){
                    if(sobranb > 2){
                        total++;
                        sobranb -=2;
                        sobraxp--;
                    }
                    else if(sobranb == 1 && sobraxp >= 2){
                        total++;
                        break;
                    }
                    else break;
                }
            }
        }
        else{
            int parejasxp = n/2;
            int res = n - parejasxp;
            int equipos = (parejasxp < m)? parejasxp:m;
            int sobraxp = n - equipos*2;
            int sobranb = m - equipos;
            total = equipos;
            if(sobranb > 0){
                while(sobranb){
                    if(sobraxp > 2){
                        total++;
                        sobraxp-=2;
                        sobranb--;
                    }
                    else if(sobraxp == 1 && sobranb >= 2){
                        total++;
                        break;
                    }
                    else break;
                }
            }

        }
        cout << total <<endl;
    }
    return 0;
}
