//# include <bits/stdc++.h>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <math.h>
# include <map>
# include <vector>
# include <set>

using namespace std;

int main(){
	int a;
	string b,c;
	cin >> a >> b >> c;
	int ini_day = 5;
	vector<int> days(367);
	if(c == "week"){
		for(int i = 1; i <= 366; ++i){
			if(ini_day == 8)
				ini_day = 1;
			days[i] = ini_day;
			ini_day++;
		}
		int ans = 0;
		for(int i = 1; i <= 366; ++i){
			if(days[i] == a)
				ans++;
		}
		cout << ans << endl;
	}
	else{
		if(a == 31){
			cout << 7 << endl;
			return 0;
		}
		else if(a == 30){
			cout << 11 << endl;
			return 0;
		}
		cout << 12 << endl;
	}
	return 0;
}