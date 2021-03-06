# include <bits/stdc++.h>

using namespace std;

const int N = 1001,M = 1001;

int dx [8] = {-1, -1, -1, 0,  0,  1, 1, 1};
int dy [8] = {-1,  0,  1, 1, -1, -1, 0, 1};

//int mytab[N][M];

bool valid (char parent, char children){
     //cout<<parent<<" "<<children<<endl;
     if(children == 'A' && parent == 'M') return true;
     if(children == 'M' && parent == 'I') return true;
     if(children == 'I' && parent == 'D') return true;
     if(children == 'D' && parent == 'A') return true;
     return false;
}

int main(){
     int n,m;
     cin >> n >> m;
     char mytab[n][m];
     
     for(int i = 0; i < n; ++i){
          scanf("%s", &mytab[i]);
     }
     
     pair<int,int> ini;
     int cont = 0;bool flag = false;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               if(mytab[i][j] == 'D'){
                    ini = make_pair(i,j);
                    flag = true;
                    break;
               }
               else cont++;
          }
          if(flag)break;
     }
     if(cont == n*m){
          cout<<"Poor Dima!"<<endl;
          return 0;
     }
     int visited [n][m];
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j)
               visited[i][j] = 0;
     }

     
     pair<int,int> actual = ini;
     stack< pair<int,int> > Q;
     Q.push(actual);
     visited[ini.first][ini.second] = 1;
     int contdima = 0;
     bool pailadir = false, paila = false;
     while(!Q.empty()){
          actual = Q.top();
          Q.pop();
          int contdir = 0;
          int possiblechildren = 0;
          cout<<"papa "<<actual.first<<" "<<actual.second<<endl;
          for(int i = 0; i < 8; ++i){
               if(actual.first + dx[i] >= n || actual.first + dx[i] < 0 || actual.second + dy[i] < 0 || actual.second + dy[i] >= m)
                    continue;
               possiblechildren++;
               char children = mytab[actual.first + dx[i]][actual.second + dy[i]];
               char parent = mytab[actual.first][actual.second];
               cout<<actual.first + dx[i]<<" "<<actual.second + dy[i]<<" "<<children<<" parent "<<parent<<" "<<valid(parent,children)<<endl;
               //cout<<i<<" "<<dx[i]<<" "<<dy[i]<<endl;
               if(!visited[actual.first + dx[i]][actual.second + dy[i]] && valid(parent, children)){
                    if(children == 'A') contdima++;
                    visited[actual.first + dx[i]][actual.second + dy[i]] = 1;
                    Q.push(make_pair(actual.first + dx[i],actual.second + dy[i]));
               }
               else if(!visited[actual.first + dx[i]][actual.second + dy[i]] && !valid(parent, children))
                    contdir++;
               
               else if(visited[actual.first + dx[i]][actual.second + dy[i]]&& valid(parent, children))
                    paila = true;
          }
          cout<<contdir<<" "<<possiblechildren<<" cuantas palabras lleva: "<<contdima<<" ciclo?"<<paila<<endl;
          //cout<<"pass"<<endl;
          if(contdir == possiblechildren){
               pailadir = true;
               break;
          }
          if(paila) break;
     }
     //cout<<paila<<" "<<pailadir<<" "<<contdima<<endl;
     if(pailadir || contdima == 0){
          cout<<"Poor Dima!"<<endl;
          return 0;
     }
     else if(paila){
          cout<<"Poor Inna!"<<endl;
          return 0;
     }
     else cout<<contdima<<endl;
     return 0;
}
