# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>

using namespace std;

int main(){
	int y; cin >> y;
	int mio[4] = {28,11,11,6};
	int mmod = y%4;
	cout << y + mio[mmod] << endl;
	return 0;
}