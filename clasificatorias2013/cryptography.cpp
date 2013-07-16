# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <cstring>
using namespace std;
const int MAXNUM = 250000;
int myPrimes [MAXNUM];
int sieve [MAXNUM];

void mySieve(){
    int primecounter = 0;
    sieve[0] = sieve[1] = 0;// is to mark every number that it's not prime 
    myPrimes[0] = 2;//myPrimes saves all the primes in each position 
    for(int i = 3; i< MAXNUM; i+=2){
        if(sieve[i]){
            myPrimes[++primecounter] = i;
            if(i*i < MAXNUM and i*i > 0)
                for(int j = i*i; j < MAXNUM; j+=i) sieve[j] = 0;//the numbers wich are multiple of some number have to ve marked as not prime
        }
    }
}

int main(){
     int n;
     memset(sieve, 1, sizeof(sieve));
     mySieve();
     cin >> n;
     for(int i = 0; i < n; ++i){
          int k;cin >> k;
          cout<<myPrimes[k - 1]<<endl;
     }
     return 0;
}
          
     
