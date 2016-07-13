# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>
# include <vector>

using namespace std;


int main(){
	int n,t; cin >> n >> t;
	vector< vector<double> > mio(n + 1);
	int llevo = 1;
	for(int i = 0; i < n + 1; ++i){
		for(int j = 0; j < llevo; ++j)
			mio[i].push_back(0);
		llevo++;
	}

	mio[0][0] = t;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < mio[i].size(); ++j){
			double entrego = mio[i][j] - 1.0;
			if(entrego > 0.0){
				mio[i][j] = 1.0;
				//cout << mio[i][j] << " ";
				ans++;
				mio[i + 1][j] += entrego*0.5;
				mio[i + 1][j + 1] += entrego*0.5;
			}
			else if(mio[i][j] == 1)
				ans++;
			//else
				//cout << mio[i][j] << " ";
		}
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}