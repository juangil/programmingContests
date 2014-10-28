# include <bits/stdc++.h>

using namespace std;

map<string,int> mio;

int distance_chord(string a, string b){
	if(mio[a] > mio[b])
		return (11 - mio[a]) + (mio[b] + 1);
	else
		return mio[b] - mio[a];
}

int main(){
	mio["C"] = 0; mio["C#"] = 1; mio["D"] = 2; mio["D#"] = 3; 
	mio["E"] = 4 ; mio["F"] = 5; mio["F#"] = 6; mio["G"] = 7; 
	mio["G#"] = 8; mio["A"] = 9; mio["B"] = 10; mio["H"] = 11;
	string a,b,c;
	cin >> a >> b >> c;
	vector<string> lleve(3);
	lleve[0] = a; lleve[1] = b; lleve[2] = c;
	/*vector<int> lleve(3);
	lleve[0] = 0; lleve[1] = 1;	lleve[2] = 2;*/
	sort(lleve.begin(), lleve.begin()+3);
	int val = 0;
	do{
		int d1,d2;
		d1 = distance_chord(lleve[0], lleve[1]);
		d2 = distance_chord(lleve[1], lleve[2]);
		//cout<<lleve[0]<<" "<<lleve[1]<<" "<<lleve[2]<<" "<<d1<<" "<<d2<<endl;
		if(d1 == 4 && d2 == 3){
			val = 1;
			break;			
		}
		if(d1 == 3 && d2 == 4){
			val = 2;
			break;
		}
	}while(next_permutation(lleve.begin(), lleve.begin() + 3));

	if(val)
		cout<<((val == 1)? "major":"minor")<<endl;
	else
		cout<<"strange"<<endl;

	return 0;
}