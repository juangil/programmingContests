# include <bits/stdc++.h>

using namespace std;

struct candy{
	int h;
	int m;
};

bool mycmp(candy a, candy b){
	if(a.h == b.h)
		return a.m > b.m;
		
	else
		return a.h < b.h;
}

int myCandys(int last, vector<candy> &type_2, vector<candy> &type_1, int my_h){
	int i = 0, j = 0;
	if(last == 1) i = 1;
	else j = 1;
	int candys = 1;
	while(1){
		if(last == 0){
			if(i >= type_1.size()) break;
			if(my_h >= type_1[i].h){
				my_h += type_1[i].m;
				last = 1;
				candys++;
				i++;
			}
			else break;
		}
		else{
			if(j >= type_2.size()) break;
			if(my_h >= type_2[i].h){
				my_h += type_2[i].m;
				last = 0;
				candys++;
				j++;
			}
			else break;
		}
	}
	return candys;
}

int main(){
	int n,x;
	while(cin >> n >> x){
		vector<candy> type_1;
		vector<candy> type_2;
		for(int i = 0; i < n; ++i){
			int t, h, m;
			cin >> t >> h >> m;
			candy c;c.h = h; c.m = m;
			if(t == 1)
				type_1.push_back(c);
			
			else
				type_2.push_back(c);
		}
		sort(type_1.begin(), type_1.end(), mycmp);
		sort(type_2.begin(), type_2.end(), mycmp);

		/*for(int i = 0; i < type_1.size(); ++i)	{
			cout<<type_1[i].h<<" "<<type_1[i].m<<endl;
		}*/
		int my_h = x;
		int last;
		if(type_1.size() == 0){
			if(type_2.size() == 0){
				cout<<0<<endl;
				continue;
			}
			else{
				if(type_2[0].h <= my_h ){
					cout<<1<<endl;
					continue;
				}
				else{
					cout<<0<<endl;
					continue;
				}

			}
		}
		else if(type_2.size() == 0){
			if(type_1.size() == 0){
				cout<<0<<endl;
				continue;
			}
			else{
				if(type_1[0].h <= my_h ){
					cout<<1<<endl;
					continue;
				}
				else{
					cout<<0<<endl;
					continue;
				}

			}
		}
		if(type_2[0].h <= my_h && !(type_1[0].h <= my_h)){
			my_h += type_2[0].m;
			last = 0;
			cout<<myCandys(last, type_2, type_1, my_h)<<endl;
		}
		else if(type_1[0].h <= my_h && !(type_2[0].h <= my_h)){
			my_h += type_1[0].m;
			last = 1;
			cout<<myCandys(last, type_2, type_1, my_h)<<endl;
		}
		else if(type_1[0].h <= my_h && type_2[0].h <= my_h){
			int cand1 = 0, cand2 = 0;
			my_h += type_2[0].m;
			last = 0;
			cand1 = myCandys(last, type_2, type_1, my_h);
		
			my_h += type_1[0].m;
			last = 1;
			cand2 = myCandys(last, type_2, type_1, my_h);
			
			cout<<max(cand1,cand2)<<endl;
		}
		else{
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}