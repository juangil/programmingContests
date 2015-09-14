# include <bits/stdc++.h>

using namespace std;

class MyRmq{
    private:
        vector< vector<int> > rmq_in;
        vector<int> mnums;
        int maxlogn_size;
    public:
        MyRmq(vector<int> tmp);
        ~MyRmq();
        void rmq_preprocess();
        int rmquery(int a, int b);
        void debug();
};

MyRmq::MyRmq(vector<int> tmp){
    rmq_in.resize(tmp.size());
    mnums = tmp;
    maxlogn_size = 20;
    for(int i = 0; i < tmp.size(); ++i)
        rmq_in[i].resize(maxlogn_size, 1 << 30);
}

MyRmq::~MyRmq(){

}

void MyRmq::rmq_preprocess(){
    for(int i = 0; i < mnums.size(); ++i)
        rmq_in[i][0] = i;
    for(int j = 1; 1 << j <= mnums.size(); ++j){
        for(int i = 0; i + (1 << j) - 1 < mnums.size(); ++i){
            if(i == 12) cout << j << endl;
            if(mnums[rmq_in[i][j - 1]] > mnums[rmq_in[i + (1 << (j - 1))][j - 1]])
                rmq_in[i][j] = rmq_in[i][j - 1];
            else
                rmq_in[i][j] = rmq_in[i + (1 << (j - 1))][j - 1];
        }
    }
}

int MyRmq::rmquery(int a, int b){
    int minterv = b - a + 1;
    if(a == b) return mnums[rmq_in[a][0]];
    int k = 0;
    int j = 1;
    while(1 << j < minterv){
        k++;
        j++;
    }
    /*cout << "min between: "<<endl;
    cout << a << " to " << a + (1 << k) << endl;
    cout << (b - (1 << k) +  1) << " to " << ((b - (1 << k) +  1) + (1 << k)) << endl;
    cout<<endl;*/
    if(mnums[rmq_in[a][k]] >= mnums[rmq_in[b - (1 << k) + 1][k]])
        return mnums[rmq_in[a][k]];
    else
        return mnums[rmq_in[b - (1 << k) + 1][k]];
}

void MyRmq::debug(){
    //cout << "pass" <<endl;
    for(int i = 0; i < rmq_in.size(); ++i){
        for(int j = 0; (j < rmq_in[i].size()) && (i + (1 << j) - 1 < mnums.size()); ++j)
            cout << "min from " << i << " to " << (i + (1 << j) - 1) << " is: " << mnums[rmq_in[i][j]] << endl;
        cout << endl;
    }
    cout << endl;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; ++t){
        int n,q; cin >> n >> q;
        vector<int> mnums(n*n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int a; cin >> a;
                mnums[(n*i) + j] = a;
            }
        }
        for(int i = 0; i < n*n; ++i){
            cout << mnums[i] << " ";
        }
        cout << endl;
        MyRmq rmq(mnums);
        rmq.rmq_preprocess();
        cout << "Case " << t << ": " << endl;
        for(int i = 0; i < q; ++i){
            int a, b, s;
            cin >> a >> b >> s;
            a--; b--;
            int l = (n*a) + b;
            int r = (n * (a + s - 1)) + (b + s - 1);
            cout << l << " " << r << endl;
            cout << rmq.rmquery(l,r) << endl;
        }

    }
    return 0;
}
