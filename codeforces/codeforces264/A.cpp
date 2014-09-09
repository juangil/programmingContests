# include <bits/stdc++.h>

using namespace std;


int main(){
	int n,s;
	cin >> n >> s;
	vector< pair<int,int> > my_sugar(n);
	for(int i = 0; i < n; ++i){
		int a,b;
		cin >> a >> b;
		pair<int,int> tmp = make_pair(a,b);
		my_sugar[i] = tmp;
	}
	int mayor =  0;
	int cont = 0;
	for(int i = 0; i < n; ++i){
		if(my_sugar[i].first == s && my_sugar[i].second > 0){
			cont++;
			continue;
		} 
		if(my_sugar[i].first <= s){
			int tmp2 = 100 - my_sugar[i].second;
			int change = 0;
			if(tmp2 < 100)
				change = tmp2;
			if(change > mayor)
				mayor = change;
	
		}
		else cont++;		
	}
	if(cont == n)cout<<-1<<endl;
	else cout<<mayor<<endl;
	return 0;

}