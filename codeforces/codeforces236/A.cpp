# include <bits/stdc++.h>

using namespace std;

int main(){

	int k, a, b, v;
	cin >> k >> a >> b >> v;
	if(a <= v){
		cout<<1<<endl;
		return 0;
	}
	else{
		bool flag = k >= b+1;
		int sections = 0, boxes = 0;
		//cout<<mio<<endl;
		int mio = 0;
		if(flag) mio = (b+1)*v;
		else mio = k*v;
		
		while(a > 0){

		}
		cout<<boxes<<endl;
	}
	return 0;

}