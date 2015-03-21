# include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> my_nums(n);
        map< int,int > appear;
        for(int i = 0; i < n; ++i){
            cin >> my_nums[i];
            appear[my_nums[i]] += 1;
        }
        map< int,int> appear1;
        vector<int> my_nums2(n);
        for(int i = 0; i < n - 1; ++i){
            int tmp; cin >> tmp;
            my_nums2[i] = tmp;
            appear1[tmp] += 1;
        }
        map< int,int> appear2;
        for(int i = 0; i < n - 2; ++i){
            int tmp; cin >> tmp;
            appear2[tmp] += 1;
        }
        map <int,int> visited;
        int remio = 0;
        for(int i = 0; i < n; ++i){
            int tmp = my_nums[i];
            if(appear[tmp] == appear1[tmp]){
                visited[i] == 1;
                continue;
            }
            else{
                cout<<tmp<<endl;
                remio = tmp;
                break;
            }
        }
        visited.clear();
        for(int i = 0; i < n - 1; ++i){
            int tmp = my_nums2[i];
            if(appear1[tmp] == appear2[tmp]){
                visited[i] == 1;
                continue;
            }
            else{
                cout<<tmp<<endl;
                break;
            }
        }
    }
    return 0;
}
