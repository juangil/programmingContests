# include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int dp [MAXN];
vector<int> myNums;
vector< vector<int> >  mySequence(MAXN);

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int lis(int i){
	if(dp[i] != -1) return dp[i];
	if(i == 0){return 1;}
	int ans = 1;
	for(int j = 0; j < i; ++j){
		if(myNums[i] > myNums[j])
			ans = max(ans, 1 + lis(j));
	}
	return ans;
}

int main(){
	int t; cin >> t;
	bool primero = true;
	bool first = true;
	int cont = 0;
	while(t--){
		if(!first)cout<<endl;
		first = false;
		string a;
		myNums.clear();
		for(int i = 0; i < MAXN; ++i){
			mySequence[i].clear();
			dp[i] = -1;
		}
		while(getline(cin, a)){
			if(cont == 1 && a == ""){primero = false;cont++; continue;}
			if(primero && a == ""){cont++;continue;}
			if(!primero && a == "")break;
			int b = toInt(a);
			myNums.push_back(b);
		}
		int ans = 1;
		for(int i = 0; i < myNums.size(); ++i){
			//cout<<myNums[i]<<" ";
			dp[i] = lis(i);
			ans = max(dp[i], ans);
		}
		//cout<<endl;
		vector<int> mySequence(ans);
		int i = 0,j;
		for(j = 1; j < myNums.size(); ++j){
			if(dp[j] > dp[i]) i = j;
		}

		int top = dp[i] - 1;
		mySequence[top] = myNums[i];
		top--;
		for(j = i -1; j >= 0; j--){
			if(myNums[j] < myNums[i] && dp[j] == dp[i] - 1){
				i = j;
				mySequence[top] = myNums[i];
				top--;
			}
		}
		cout<<"Max hits: "<<ans<<endl;
		for(i = 0; i < mySequence.size(); ++i)
			cout<<mySequence[i]<<endl;
		
		
	}

	return 0;
}

