# include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int lli;

struct diagonal{
	int x;
	int y;
	lli val;
};

int main(){ __
	int n; cin >> n;
	lli chess[n][n];
	vector<lli> diag1(2*n - 1, 0);
	vector<lli> diag2(2*n - 1, 0);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> chess[i][j];
			int idx1 = (i < j)? ((j - i)+(n - 1)):(i - j);
			int idx2 = i + j;
			diag1[idx1] += chess[i][j];
			diag2[idx2] += chess[i][j];
		}
	}
	/*for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int idx1 = (i < j)? ((j - i)+(n - 1)):(i - j);
			int idx2 = i + j;
			cout<<i<<" "<<j<<" "<<"diag1 "<<idx1<<" diag2 "<<idx2<<endl;
			cout<<"result diag1: "<<diag1[idx1]<<" result diag2: "<<diag2[idx2]<<endl;
			cout<<endl;
		}
	}*/

	lli max1= -1, max2 = -1;
	int x1 = -1,y1 = -1, x2 = -1, y2 = -1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int idx1 = (i < j)? ((j - i)+(n - 1)):(i - j);
			int idx2 = i + j;
			lli tmp = diag1[idx1] + diag2[idx2] - chess[i][j];
			if(i%2 == 0){
				if(j%2 == 0){			
					if(tmp > max1){
						max1 = tmp;
						x1 = i; y1 = j;
					}
				}
				else{
					if(tmp > max2){
						max2 = tmp;
						x2 = i; y2 = j;
					}
				}
			}
			else{
				if(j%2 != 0){					
					if(tmp > max1){
						max1 = tmp;
						x1 = i; y1 = j;
					}
				}
				else{
					if(tmp > max2){
						max2 = tmp;
						x2 = i; y2 = j;
					}
				}
			}
		}
	}
	lli result = max1 + max2;
	cout<<result<<endl;
	cout<<x1 + 1<<" "<<y1 + 1<<" "<<x2 + 1<<" "<<y2 + 1<<endl;
	return 0;		
}	