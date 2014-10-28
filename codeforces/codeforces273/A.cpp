# include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int lli;

int main(){
	int n,m;
	cin >> n >> m;
	lli ans1 = 1;
	lli ans2 = 1;
	if(m == n){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	if(m == 1){
		if(n%2 == 0){
			lli tmp = n/2;
			ans1 = tmp*(n - 1);
		}
		else{
			lli tmp = (n - 1)/2;
			ans1 = (n)*(tmp);
		}
		cout<<ans1<<" "<<ans1<<endl;
		return 0;
	}
	if((n/m) == 1){
		lli grupos = m - 1;
		lli quedan = n - grupos;
		if(quedan%2 == 0){
			lli tmp = (quedan/2);
			ans2 = tmp*(quedan - 1);
		}
		else{
			lli tmp = ((quedan - 1)/2);
			ans2 = (quedan)*tmp;
		}
		lli grupos2 = n/2;
		lli faltan = m - (grupos2 + ((n%2 == 0)? 0:1));
		quedan = n - 2*grupos2;
		grupos2 -= faltan;
		cout<<grupos2<<" "<<ans2<<endl;				
		return 0;		
	}
	else{
		  lli grupos2 = n/2;
		  quedan = n - 2*grupos2;
		  if(quedan){
		  	if(m > grupos2 + 1){
		  		faltan = m - grupos2 + 1;
		  		grupos2 -= faltan;
		  	}
		  	
		  }
		}
		return 0;
	}

}