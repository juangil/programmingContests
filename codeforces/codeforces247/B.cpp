# include <bits/stdc++.h>

using namespace std;

int G [5][5];


int main(){
	for(int i = 0; i< 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> G[i][j];
	vector<int> mio(5);
	mio[0] = 0; mio[1] = 1; mio[2] = 2;
	mio[3] = 3; mio[4] = 4;
	//vector<int> may(5);
	int ans = 0;
	do{
		int total_cost = 0;
		for(int i = 0; i < 5; ++i)
			for(int j = i ; j + 1 < 5; j+=2)	
				total_cost += G[mio[j]][mio[j+1]] + G[mio[j+1]][mio[j]];
	
		ans = max(total_cost, ans);
	}while(next_permutation(mio.begin(), mio.end()));

	cout<<ans<<endl;
	return 0;
}
