# include <bits/stdc++.h>

using namespace std;

int kk = 0;
double my_prob;

void m_reverse(vector<int> &tmp, int i, int j){
	while(j >= i){
		int mio = tmp[j];
		tmp[j] = tmp[i];
		tmp[i] = mio;
		j--;
		i++;
	}
	return;
}

int count_inversions(vector<int> &tmp){
	int ret = 0;
	for(int i = 0; i < tmp.size(); ++i){
		for(int j = i; j < tmp.size(); ++j)
			if(tmp[j] < tmp[i])
				ret++;
	}
	return ret;
}

double expected_value(vector<int> tmp, int k, double acum_prob){
	if(k == kk){
		//cout<<count_inversions(tmp)<<endl;
		return count_inversions(tmp)*(acum_prob);
	}
	double ret = 0.0;
	for(int i = 0; i < tmp.size(); ++i){
		for(int j = i; j < tmp.size(); ++j){
			vector<int> mio = tmp;
			m_reverse(mio, i, j);
			ret += expected_value(mio, k + 1, acum_prob*my_prob);
		}
	}
	return ret;	
}

int main(){
	int n,k;
	while(cin >> n >> k){
		vector<int> my_nums(n);
		my_prob = 1.0/((n*(n+1.0))/2.0);
		//cout<<my_prob<<endl;
		for(int i = 0; i < n; ++i)
			cin >> my_nums[i];
		kk = k;
		printf("%.16lf\n", expected_value(my_nums, 0, 1.0));
	}
}