# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; ++t){
		string s;
		cin >> s;
		string result = ""; 
		result += s[0];
		for(int i = 1; i < s.size(); ++i){
			int mlim = result.size();
			if(s[i] < result[0])
				result = result + s[i];
			else
				result = s[i] + result;
		}
		cout << "Case #" << t << ": " << result << endl;
	}
	return 0;
}
