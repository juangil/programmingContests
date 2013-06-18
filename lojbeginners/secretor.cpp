# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# define FR(i,n) for(int i = 0; i < n; i++)
# define PI 2*acos(0.0)


using namespace std;

typedef unsigned int uint;

uint id;



uint primerCaso(uint x){
	int i;
	for(i=0;i<32;i++){
		if (!((x>>i) & 1))
			break;
	}
	x = x | (1<<i);
	x = x ^ (1<<(i-1));
	id = i-2;
	return x;
}

uint segundoCaso(uint x)
{
        bool flag = false;
        int cont = 0, i, numones;
        uint num = 0xFFFFFFFF;
        //cout<<"segundo caso"<<endl;
        //x = primerCaso(x);
        for(i = 0; i < 32; i++)
        {
          if((x>>i) & 1)
          {
             cont += 1;
             flag = true;
             
          }
          else
          {
             if(flag)
               break;
          }
        }
        cont --;
        
        x = x | (1<<i);
	x = x ^ (1<<(i-1));
	
	if(cont == 0) return x;
	id = i - 2;
	num <<= id+1;	
        x = x & num;	
	FR(k, cont)
	   x = x | (1<<k);
	return x;
}
	   
	
 
int main()
{
   int t = 0;
   scanf("%d", &t);
   
   FR(i, t)
   {
      uint n = 0, numones = 0, idx = 0;      
      scanf("%u", &n);
      if(n & 1) n = primerCaso(n); 
      else n = segundoCaso(n);
      printf("Case %d: %u\n", i+1, n); 
       
   }
   return 0;
 }   
      
