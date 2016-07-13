# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

vector<string> mnums(10);


int main(){
	int T; cin >> T;
	mnums[0] = "ZERO";
	mnums[1] = "ONE"; 
	mnums[2] = "TWO"; 
	mnums[3] = "THREE"; 
	mnums[4] = "FOUR";
	mnums[5] = "FIVE"; 
	mnums[6] = "SIX"; 
	mnums[7] = "SEVEN";
	mnums[8] =  "EIGHT"; 
	mnums[9] = "NINE"; 
	for(int t = 1; t <= T; ++t){
		string mio; cin >> mio;
		vector< vector<int> > ocurrences(10);
		for(int i = 0; i < ocurrences.size(); ++i){
			vector<int> tmp(mnums[i].size(), 0);
			ocurrences[i] = tmp;
		}
		vector<int> oc_digits(9,0);
		for(int i = 0; i < mio.size(); ++i){
			char tmp = mio[i];
			for(int j = 0; j < mnums.size(); ++j){
				for(int k = 0; k < mnums[j].size(); ++k){
					if(mnums[j][k] == tmp){
						ocurrences[j][k] += 1;
					}

				}
			}
		}
		for(int i = 0; i < ocurrences.size(); ++i){
			int mmin = 10000000;
			for(int j = 0; j < ocurrences[i].size(); ++j){
				mmin = min(ocurrences[i][j], mmin);
			}
			if(mmin > 0){
				if(i == 3){
					if(ocurrences[i][3] < 2*mmin && ocurrences[i][4] < 2*mmin)
						mmin = 0;
				}
				if(i == 7){
					if(ocurrences[i][1] < 2*mmin && ocurrences[i][3] < 2*mmin)
						mmin = 0;
				}
				if(i == 9){
					if(ocurrences[i][0] < 2*mmin && ocurrences[i][2] < 2*mmin)
						mmin = 0;
				}
			}
			oc_digits[i] = mmin;
		}
		cout << "Case #" << t << ": ";
		for(int i = 0; i < oc_digits.size(); ++i){
			for(int j = 0; j < oc_digits[i]; ++j){
				cout << i;
			}
		}
		cout << endl;

	}
	return 0;
}