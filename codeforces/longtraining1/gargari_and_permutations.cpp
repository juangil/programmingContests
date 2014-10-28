# include <bits/stdc++.h>

using namespace std;

int N;

vector<int> toposort(vector< vector<int> > &G, vector<int> &roots, vector<int> in_degree){
	vector<int> ret;
	int removed[N][N];

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			removed[i][j] = 0;

	while(!roots.empty()){
		int tmp = roots.back();
		roots.pop_back();
		ret.push_back(tmp);
		for(int i = 0; i < G[tmp].size(); ++i){
			int children = G[tmp][i];
			if(removed[tmp][children]) continue;
			removed[tmp][children] = 1;
			in_degree[children]--;
			if(in_degree[children] == 0)
				roots.push_back(children);
		}
	}

	return ret;
}

int main(){
	int n, k;cin >> n >> k;
	vector< vector<int> > G(n);
	vector< vector<int> > my_nums(k);
	N = n;

	for(int i = 0; i < k; ++i){
		my_nums[i].resize(n);
		for(int j = 0; j < n; ++j)
			cin >> my_nums[i][j];
	}
	
	int mio [n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			mio[i][j] = 0;

	for(int i = 0; i < k; ++i){
		for(int j = 0; j < n; ++j){
			int a = my_nums[i][j];
			for(int l = j + 1; l < n; ++l){				
				int b = my_nums[i][l];				
				mio[a - 1][b - 1] += 1;				
			}
		}
	}

	vector<int> in_degree (n);
	for(int i = 0; i < n; ++i)
		in_degree[i] = 0;

	for(int i = 0; i < n; ++i){		
		for(int j = 0; j < n; ++j){
			if(mio[i][j] == k){
				G[i].push_back(j);
				in_degree[j]++;
			}
		}				
	}

	vector<int> roots;
	for(int i = 0; i < n; ++i)
		if(in_degree[i] == 0)roots.push_back(i);

	vector<int> sorted_graph = toposort(G, roots, in_degree);

	vector<int> pos_sorted(sorted_graph.size());
	for(int i = 0; i < sorted_graph.size(); ++i)
		pos_sorted[sorted_graph[i]] = i;

	vector<int> lcsb(sorted_graph.size(), 1);

	for(int i = 0; i < sorted_graph.size(); ++i){
		int parent = sorted_graph[i];
		//cout<<"parent: "<<parent<<endl;
		for(int j = 0; j < G[parent].size(); ++j){
				int children = G[parent][j];
				//cout<<"   children: "<<children<<" ";
				int idx_child = pos_sorted[children];
				lcsb[idx_child] = max(lcsb[i] + 1, lcsb[idx_child]);
				
		}
	}
	int mmax = 1;
	for(int i = 0; i < lcsb.size(); ++i)
		mmax = max(lcsb[i], mmax);
	cout<<mmax<<endl;
	//toposort
	//algorithm over toposort
	//out
	return 0;
}