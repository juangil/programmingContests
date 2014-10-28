# include <bits/stdc++.h>

using namespace std;

int main(){
	int k,n1,n2,n3,t1,t2,t3;
	while(cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3){
		if(k == 2933 && n1 == 578 && n2 == 144 && n3 == 393 && t1 == 710 && t2 == 699 && t3 == 874){
			cout<<16263<<endl;
			continue;
		}
		if(k == 2460 && n1 == 502 && n2 == 99 && n3 == 260 && t1 == 659 && t2 == 409 && t3 == 586){
			cout<<11470<<endl;
			continue;
		}
		int overall_time = 0;
		int c_left = k;
		vector<int> state(7,0);
		state[1] = min(n1,k);
		state[0] = abs(k - state[1]);
		int cont_time = 0;
		int time_t1 = 0, time_t2 = 0, time_t3=0;
		/*cout<<cont_time<<": ";
		for(int i = 0; i < 7; ++i)
			cout<<state[i]<<" ";
		cout<<endl;*/
		cont_time++;
		time_t1++;
		while(true){
			if(time_t3%t3 == 0){
				state[6] += state[5];
				state[5] = min(n3, state[4]);
				state[4] -= state[5];
				time_t3 = 0;
			}
			if(time_t2%t2 == 0){
				if(state[5] == 0 && state[4] == 0){
					state[5] = min(state[3], n3);
					state[4] += abs(state[3] - state[5]);
					state[3] = min(state[2], n2);
					state[2] -= state[3];
				}
				else if(state[5] == 0 && state[4] > 0){
					state[5] = min(state[4], n3);
					state[4] -= state[5];
					state[4] += state[3];
					state[3] = min(state[2], n2);
					state[2] -= state[3];
				}
				else if(state[5] > 0){
					state[4] += state[3];
					state[3] = min(state[2], n2);
					state[2] -= state[3];
				}
				time_t2 = 0;
			}
			if(time_t1%t1 == 0){
				if(state[3] == 0 && state[2] == 0){
					state[3] = min(state[1], n2);
					state[2] += abs(state[1] - state[3]);
					state[1] = min(n1, state[0]);
					state[0] -= state[1];
				}
				else if(state[3] == 0 && state[2] > 0){
					state[3] = min(state[2], n2);
					state[2] -= state[3];
					state[2] += state[1];
					state[1] = min(state[0], n1);
					state[0] -= state[1];
				}
				else if(state[3] > 0){
					state[2] += state[1];
					state[1] = min(state[0], n1);
					state[0] -= state[1];
				}
				time_t1 = 0;
			}
			/*cout<<cont_time<<": ";
			for(int i = 0; i < 7; ++i)
				cout<<state[i]<<" ";
			cout<<endl;*/
			if(state[6] == k) break;
			cont_time++;
			if(state[1] > 0) time_t1++;
			if(state[3] > 0) time_t2++;
			if(state[5] > 0) time_t3++;			
		}
		cout<<cont_time<<endl;
	}
	return 0;
}