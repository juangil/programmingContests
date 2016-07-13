# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>
# include <map>

using namespace std;cl

bool checksym(string s){
	for(int i = 0; i < s.size(); ++i){
		if(s[i] != '+')
			return false;
	}
	return true;
}

int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; ++t){
		string s;
		cin >> s;
		int mnum = 0;
		while(!checksym(s)){
			char ini = s[0];
			for(int i = 0; i < s.size(); ++i){
				if(s[i] == ini)
					s[i] = (s[i] == '+')? '-':'+';
				else
					break;
			}
			mnum += 1;
		}
		cout << "Case #" << t << ": " << mnum << endl;
	}
	return 0;
}