# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>

using namespace std;

void extractDigits(int mnum, set<int> &mio){
	// << mnum << endl;
	while(mnum >= 10){
		int mdigit = mnum % 10;
		//cout << "inserto: " << mdigit << endl;
		mio.insert(mdigit);
		mnum /= 10;
	}
	//cout << "inserto el ultimo: " << mnum << endl;
	mio.insert(mnum);
}


int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; ++t){
		int mnum; cin >> mnum;
		set<int> mio;
		int tmp = mnum;
		if(mnum == 0){
			cout << "Case #" << t << ": INSOMNIA" << endl;
			continue;
		}
		int cont = 0;
		while(mio.size() != 10){
			//cout << mnum << endl;
			extractDigits(mnum, mio);
			if(mio.size() == 10)
				break;
			//cout << endl;
			mnum += tmp;
			cont++;
		}
		cout << "Case #" << t << ": " << mnum << endl;
	}
	return 0;
}