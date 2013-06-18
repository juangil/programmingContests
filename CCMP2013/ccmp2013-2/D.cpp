using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include <limits> 
#include <queue> 
#include <stack> 
#include <set>
#include <map>
#include <cstring> 
#define MP 5005
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,v) for( typeof (v.begin()) x = v.begin();x!=v.end();++x)
#define D(x) cout<< #x " = "<<(x)<<endl

vector<int> g[MP];
int d[MP],low[MP], scc[MP];
bool stacked[MP];

stack<int> s;
int ticks,current_scc;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for(int k=0,m=out.size(); k<m;++k){
        const int &v = out[k];
        if(d[v] == -1){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(stacked[v]){
            low[u] = min(low[u],low[v]);
        }
    }
    
    if(d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        }while( u != v);
        current_scc++;        
    }
}
int main(){
    int a,b,aa,bb;
    int caso = 1;
    while(cin>>a and a){
        cin>>b;
        memset(d,-1,sizeof(d));
        memset(stacked,0,sizeof(stacked));
        memset(scc,-1,sizeof(scc));
        ticks = 0;
        current_scc = 0;
        s = stack<int>();
        
        For(i,a)g[i].clear();
        For(i,b){
            cin>>aa>>bb;
            aa--;
            bb--;
            g[aa].push_back(bb);
        }
        For(i,a){
            if(scc[i]==-1)tarjan(i);
        }

        map<int,vector<int> > mio;
        int valid[current_scc];
        memset(valid,1,sizeof(valid));
        For(i,a){
            int paila = 0;
            if(valid[scc[i]]){
                foreach(h,g[i]){
                    if(scc[*h] != scc[i]){
                        valid[scc[i]] = false;
                        break;
                    }
                }
            }
            
            if(valid[scc[i]])
                mio[scc[i]].push_back(i);
            else
                mio[scc[i]].clear();
        }
        set<int> ans;
        For(i,a){
            if(g[i].size() == 0)
            ans.insert(i);
        }
        foreach(it,mio){
            if(it->second.size()> 0){
                For(k,it->second.size()){
                    ans.insert(it->second[k]);
                }
            }
        }
        
        int i=0;
        foreach(xx,ans){
            cout<<((*xx)+1)<<((i ==ans.size()-1)?"\n":" ");
            i++;
        }

        if(ans.size()==0)
            cout<<endl;
         /*   
        if(caso == 18){
            cout<<"esto es: ";
            For(i,a){
                cout<<scc[i]<<endl;
            }
        
        }*/
        ++caso;
    }

    return 0;
}
