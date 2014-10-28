# include <bits/stdc++.h>

using namespace std;


struct PT { 
  int x, y; 
  PT() {}
  PT(int x, int y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (int c)     const { return PT(x*c,   y*c  ); }
  PT operator / (int c)     const { return PT(x/c,   y/c  ); }
};

int dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
int dist2(PT p, PT q)   { return dot(p-q,p-q); }
int cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }


vector<PT> rotate_point_4dir(pair<PT,PT> to_rotate){
	
	vector<PT> ret(4);
	//cout<<"pass3"<<endl;
	ret[0] = to_rotate.first;

	
	PT vir_rot = ret[0] - to_rotate.second;
	ret[1] = to_rotate.second + RotateCCW90(vir_rot);

	vir_rot = ret[1] - to_rotate.second;
	ret[2] = to_rotate.second + RotateCCW90(vir_rot);
	
	vir_rot = ret[2] - to_rotate.second;
	ret[3] = to_rotate.second + RotateCCW90(vir_rot);
	return ret;
}

bool checkSquare(PT a, PT b, PT c, PT d){
	PT ref1 = b - a;
	PT ref2 = c - a;
	PT ref3 = d - a;
	if((ref1.x == 0 && ref1.y == 0) || (ref2.x == 0 && ref2.y == 0) || (ref3.x == 0 && ref3.y == 0)) return false;
	int dotprod1 = dot(ref1, ref2);
	int dotprod2 = dot(ref1, ref3);
	int dotprod3 = dot(ref2, ref3);
	if(dotprod1 == 0){
		if(dist2(d, c) == dist2(d, b)){
			if(dist2(a,b) == dist2(d,c))return true;
			else return false;
		}
		else return false;
	}
	else if(dotprod2 == 0){
		if(dist2(c, b) == dist2(c, d)){
			if(dist2(a,b) == dist2(b,c))return true;
			else return false;
		}
		else return false;
	}
	else if(dotprod3 == 0){
		if(dist2(b, c) == dist2(b, d)){
			if(dist2(a,c) == dist2(b,c)) return true;
			else return false;
		}
		else return false;
	}
	else return false;
 }

int main(){
	int n;
	while(cin >> n){
		vector< vector< pair<PT,PT> > > regiment(n);
		int idr = 1;
		for(int i = 1; i <= 4*n; ++i){
			int x,y,a,b;			
			cin >> x >> y >> a >> b;
			pair<PT,PT> tmp = make_pair(PT(x,y), PT(a,b));
			regiment[idr - 1].push_back(tmp);
			if(i%4 == 0) idr++;
		}
		for(int i = 0; i < regiment.size(); ++i){
			vector< pair<PT,PT> > current = regiment[i];
			//cout<<"pass"<<endl;
			vector<PT> mole1 = rotate_point_4dir(current[0]);
			vector<PT> mole2 = rotate_point_4dir(current[1]);
			vector<PT> mole3 = rotate_point_4dir(current[2]);
			vector<PT> mole4 = rotate_point_4dir(current[3]);			
			PT a,b,c,d;
			int mmin = 1 << 30;			
			for(int j = 0; j < 4; j++){
				a = mole1[j];
				for(int k = 0; k < 4; k++){
					b = mole2[k];
					for(int l = 0; l < 4; l++){
						c = mole3[l];
						for(int m = 0; m < 4; m++){
							d = mole4[m];							
							if(checkSquare(a,b,c,d)){
								int moves = j + k + l + m;
								/*if(i == 2){
									cout<<mole1[j]<<", "<<mole2[k]<<", "<<mole3[l]<<", "<<mole4[m]<<" "<<endl;
									cout<<j<<" "<<k<<" "<<l<<" "<<m<<" square: "<<(checkSquare(a,b,c,d))<<endl;		
									cout<<	j + k + l + m<<endl;			
								}*/
								if(moves < mmin)
									mmin = moves;
							}
						}
					}
				}
			}
			cout<<((mmin==1<<30)? -1:mmin)<<endl;
		}
	}
	return 0;
}
