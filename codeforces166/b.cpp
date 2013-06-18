# include <iostream>
# include <cstdlib>
# include <set>
# include <vector>

using namespace std;

vector<int> sieve;
set<int> primes;

void  prime(int n)
{
    sieve = vector<int> (n+5,1);    
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < n; i++)
    {
       
       if(sieve[i])
       {          
          primes.insert(i);          
          for(int j = 2*i; j < n; j += i) 
          {     
                //cout<<j<<endl;                 
                sieve[j] = 0;
          }    
       }
     }    
}

int matr [501][501];

int nmovimientos(int n)
{
    int k = (*primes.lower_bound(n));
    return k - n;
}

int search(int n, int m)
{
   int min = 1000000;
   int tmp = 0;
   for(int i = 0; i < n; i++)
   {
       tmp = 0; 
       for(int j = 0; j < m; j++)
       {
          tmp += nmovimientos(matr [i][j]);
       }
       if (tmp < min)
           min = tmp;
   }
   for(int k = 0; k < m; k++)
   {
       tmp = 0;
       for(int l = 0; l < n; l++)
       {
          tmp += nmovimientos(matr [l][k]);
       }
       if (tmp < min)
           min = tmp;
   }
   return min;
}
          
                   
int main()
{
   int m, n;
   cin >> n >> m;   
   prime(100004);
   //cout<<"pas"<<endl;
   for(int i = 0; i < n; i++)
   {
     
     for(int j = 0; j < m; j++)
     {
        cin >> matr [i][j];
     }
   }
   
   cout << search(n,m) << endl ;
   return 0;
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
