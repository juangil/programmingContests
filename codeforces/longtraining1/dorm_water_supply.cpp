# include <bits/stdc++.h>

using namespace std;

struct mio{
	int a; int b;
	int c;
};

int dfs(vector< vector< pair<int,int> > > &G, int ini, int target){
	vector<int> visited(G.size(), 0);
	stack< pair<int,int> > Q;
	Q.push(make_pair(ini,1<<30));
	int menor = 1 << 30;
	while(!Q.empty()){
		pair<int,int> current = Q.top();
		Q.pop();
		int parent = current.first;
		int cap = current.second;
		visited[parent] = 1;
		if(cap < menor) menor = cap;
		if(parent == target) return menor;
		for(int i = 0; i < G[parent].size(); ++i){
			pair<int,int> house = G[parent][i];
			int children = house.first;
			if(visited[children]) continue;
			else Q.push(house);			
		}
	}
	return -1;
}

int main(){
	int n,m;
	while(cin >> n >> m){
		vector< vector< pair<int,int> > > G(n);
		vector<int> in_degree(n,0);
		vector<int> out_degree(n,0);
		for(int i = 0; i < m; ++i){
			int a,b,c;
			cin >> a >> b >> c;
			pair<int,int> tmp = make_pair(b-1,c);
			G[a-1].push_back(tmp);
			in_degree[b-1] += 1;
			out_degree[a-1] += 1;
		}
		vector<int> ini;
		vector<int> finish;
		for(int i = 0; i < n; ++i){
			if(in_degree[i] == 1 && out_degree[i] == 0)
				finish.push_back(i);
			else if(in_degree[i] == 0 && out_degree[i] == 1)
				ini.push_back(i);			
		}
		vector<mio> ans;
		for(int i = 0; i < ini.size(); ++i){
			int a = ini[i];
			//cout<<a<<" ";
			int b;
			int ret = 0;
			for(int j = 0; j < finish.size(); ++j){
				b = finish[j];
				//cout<<b<<" ";
				ret = dfs(G,a,b);
				//cout<<ret<<endl;
				mio lleve;
				lleve.a = a; lleve.b = b; lleve.c = ret;
				if(ret != -1) ans.push_back(lleve);
			}
			
		}
		cout<<ans.size()<<endl;
		for(int i = 0; i < ans.size(); ++i)
			cout<<(ans[i].a+1)<<" "<<(ans[i].b+1)<<" "<<ans[i].c<<endl;


	}
}