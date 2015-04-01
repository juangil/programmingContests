# include <bits/stdc++.h>

using namespace std;


class MyRmq{
    private:
        vector<int> mnums;
        vector<int> rmq_in;
        int mm_size;
    public:
        MyRmq(vector<int> &init);
        ~MyRmq();
        void rmq_preprocess();
        int rmquery(int a, int b);
        void debug();
};

MyRmq::MyRmq(vector<int> &init){
    mnums = init;
}

MyRmq::~MyRmq(){

}

void MyRmq::rmq_preprocess(){
    mm_size = (int)floor(sqrt(mnums.size()));
    vector<int> tmp (mm_size, 1 << 30);
    int cont_interval = 0;
    int slot_rmq = 0;
    for(int i = 0; i < mnums.size(); ++i){
        if(slot_rmq == mm_size)
            tmp.push_back(1 << 30);

        if(mnums[i] < tmp[slot_rmq]){
            tmp[slot_rmq] = i;
            cont_interval++;
        }
        if((i + 1) % mm_size == 0){
            cont_interval = 0;
            slot_rmq++;
        }
    }
    rmq_in = tmp;
}

int MyRmq::rmquery(int a, int b){
    if(a == b) return mnums[a];
    int miss_slot = mnums.size() - (mnums.size() % mm_size);

    int a_slot_rmq = (a >= miss_slot)? (rmq_in.size() - 1):(a / mm_size);
    int b_slot_rmq = (b >= miss_slot)? (rmq_in.size() - 1):(b / mm_size);
    if(a_slot_rmq == b_slot_rmq)
        return mnums[rmq_in[a_slot_rmq]];
    //cout << a_slot_rmq << " " << b_slot_rmq << endl;
    int i = a, a_min = mnums[a];
    for(;(i + 1) % mm_size != 0; i++)
        a_min = min(a_min, mnums[i]);

    int b_min = mnums[b];
    for(i = b;(i + 1) % mm_size != 0; i--)
        b_min = min(b_min, mnums[i]);

    int tmp_min = (a_slot_rmq + 1 == b_slot_rmq)? a_min:mnums[rmq_in[a_slot_rmq + 1]];
    //cout << a_min << " " << tmp_min << " " << b_min <<endl;
    //cout << a_slot_rmq << " "  << b_slot_rmq << endl;
    for(i = a_slot_rmq + 1; i < b_slot_rmq; ++i)
        tmp_min = min(mnums[rmq_in[i]], tmp_min);

    //cout << a_min << " " << tmp_min << " " << b_min <<endl;
    return min(a_min, min(tmp_min, b_min));
}

void MyRmq::debug(){
    for(int i = 0; i < rmq_in.size(); ++i)
        cout << mnums[rmq_in[i]] << " ";
    cout << endl;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> mio(n);
        for(int i = 0; i < n; ++i)
            cin >> mio[i];

        MyRmq rmq(mio);
        rmq.rmq_preprocess();
        //rmq.debug();
        for(int i = 0; i < m; ++i){
            int a,b;
            cin >> a >> b;
            cout << rmq.rmquery(a,b) << endl;
        }
    }
    return 0;
}
