# include <bits/stdc++.h>

using namespace std;

typedef long long int  lli;

int main(){
	lli n;
	while(cin >> n){
		if(n%2 == 0){
			lli my_n = n/2;
			lli ans1 = ((2*my_n*(my_n + 1))/2) - my_n;
			lli ans2 = ((2*my_n*(my_n + 1))/2);
			cout<<ans2 - ans1<<endl;
		}
		else{
			lli my_n = n/2;
			lli ans1 = ((2*(my_n+1)*(my_n + 2))/2) - (my_n+1);
			lli ans2 = ((2*my_n*(my_n + 1))/2);
			cout<<ans2 - ans1<<endl;
		}
	}
	return 0;
}