# include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
  while(t--){
    int n,l,r;
    cin >> n >> l >> r;
    if(n < l){
      cout<<"No"<<endl;
      continue;
    }
    if(n == l || n == r)
          cout<<"Yes"<<endl;
  }


	return 0;
} 
