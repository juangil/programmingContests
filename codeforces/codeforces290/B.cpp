# include <bits/stdc++.h>

using namespace std;

bool dfs(vector< vector<int> > &G, int ini){
	vector<int> visited(G.size(), 0);
	vector<int> parent(G.size(), -1);
	stack<int> Q;
	Q.push(ini);
	visited[ini] = 1;
	while(!Q.empty()){
		int current = Q.top();
		//cout<<current<<" ";
		Q.pop();
		for(int i = 0; i < G[current].size(); ++i){
			int children = G[current][i];
			parent[children] = current;
			if(!visited[children]){
				Q.push(children);
				visited[children] = 1;
			}
			else if(children != parent[current])
				return true;
		}
	}
	return false;
}

int main(){
	int n,m;
	while(cin >> n >> m){
		char mio[n][m];
		int my_nums[n][m];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <m; ++j){
				cin >> mio[i][j];
				my_nums[i][j] = i*m + j;
			}
		}		
		vector< vector<int> > G(n*m);
		map< pair<int,int>, int> mmap;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <m; ++j){
				int tmp = mio[i][j];
				int nodo = my_nums[i][j];
				if(i != 0){					
					if(tmp == mio[i - 1][j]){												
						G[nodo].push_back(my_nums[i - 1][j]);						
						/*G[my_nums[i - 1][j]].push_back(nodo);
						pair<int,int> tmp = make_pair(nodo, my_nums[i - 1][j]);
						mmap[tmp] = 1;*/
					}
				}
				if(i != n - 1){
					if(tmp == mio[i + 1][j]){
						G[nodo].push_back(my_nums[i + 1][j]);
						/*G[my_nums[i + 1][j]].push_back(nodo);
						pair<int,int> tmp = make_pair(nodo, my_nums[i + 1][j]);
						mmap[tmp] = 1;*/
					}

				}
				if(j != 0){
					if(tmp == mio[i][j - 1]){
						G[nodo].push_back(my_nums[i][j - 1]);
						/*G[my_nums[i][j - 1]].push_back(nodo);
						pair<int,int> tmp = make_pair(nodo, my_nums[i][j - 1]);
						mmap[tmp] = 1;*/
					}
				}
				if(j != m - 1){
					if(tmp == mio[i][j + 1]){						
						G[nodo].push_back(my_nums[i][j + 1]);
						/*G[my_nums[i][j + 1]].push_back(nodo);
						pair<int,int> tmp = make_pair(nodo, my_nums[i][j + 1]);
						mmap[tmp] = 1;*/
					}
				}
			}
		}
		int cont = 0;
		/*for(int i = 0; i < G.size(); ++i){
			cout<<i<<"("<<G[i].size()<<"): ";
			for(int j = 0; j < G[i].size(); ++j)
				cout<<G[i][j]<<" ";
			cout<<endl;
		}*/
		for(int i = 0; i < G.size(); ++i){
			if(dfs(G, i))				
				break;
			cont++;
		}
		string ret = (cont == n*m)? "No":"Yes";
		cout<<ret<<endl;
	}
	return 0;
}