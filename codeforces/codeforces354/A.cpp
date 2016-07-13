# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>
# include <vector>

using namespace std;


int main(){
	int n; cin >> n;
	vector<int> mio(n);
	int pos1, posn;
	for(int i = 0; i < n; ++i){
		cin >> mio[i];
		if(mio[i] == 1)
			pos1 = i;
		else if(mio[i] == n)
			posn = i;
	}
	int a = min(pos1, posn);
	int b = max(pos1, posn);
	int mdist = b - a;
	int gano = max(a, n - 1 - b);
	//cout << a << " " << n - b << endl;
	cout << mdist + gano << endl;
	return 0;
}