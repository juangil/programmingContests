# include <bits/stdc++.h>

using namespace std;

int main(){
    string a; cin >> a;
    int nn = 0, ee = 0, ii = 0, tt = 0, nnn = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'n') nn += 1;
        if(a[i] == 'i') ii += 1;
        if(a[i] == 'e') ee += 1;
        if(a[i] == 't') tt += 1;
        if(nn%3 == 0) nnn += 1;
    }
    /*std::map<char,int>::iterator it;
    for (it=mymap.begin(); it!=mymap.end(); ++it){
        if(it->first == 'n') nn = it->second/3;
        if(it->first == 'i') ii = it->second; 
        if(it->first == 'e') ee = it->second/3; 
        if(it->first == 't') tt = it->second; 
    }*/
    int cont = 0;
    if (nn >= 3 && ii >= 1 && ee >= 3 && tt >= 1) {
        cont++;
        ii -= 1;
        ee -= 3;
        tt -= 1;
        nn -= 3;
    }
    if (!cont) {
        cout<<0<<endl;
        return 0;
    }
    
    while(nn >= 2 && ii >= 1 && ee >= 3 && tt >= 1){
        ii -= 1;
        ee -= 3;
        tt -= 1;
        nn -= 2;
        cont++;
    }
    cout<<cont<<endl;
    return 0;
}
