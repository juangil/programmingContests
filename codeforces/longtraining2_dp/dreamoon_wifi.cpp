# include <bits/stdc++.h>

using namespace std;

int N;
int target;
string mio;

int solve(int i, int step){
	if(i == N && step == target) return 1;
	else if(i == N && step != target) return 0;
	int ret = 0;
	if(mio[i] != '?'){
		step += (mio[i] == '+')? 1:-1;
		ret += solve(i + 1, step);
	}
	else
		ret += solve(i + 1, step + 1) + solve(i + 1, step - 1);
	return ret;
}

int main(){
	string a,b;
	while(cin >> a >> b){
		int ini = 0;
		for(int i = 0; i < a.size(); ++i)
			ini += (a[i] == '+')? 1:-1;
		int cont = 0;
		for(int i = 0; i < b.size(); ++i)
			cont += (b[i] == '?')? 1:0;
		int bmask = 1 << cont;
		//cout<<bmask<<endl;
		mio = b;
		N = a.size();
		target = ini;
		int favorables = solve(0, 0);
		double msol = (double)favorables/(double)bmask;
		printf("%.16lf\n", msol);
	}
	return 0;
}