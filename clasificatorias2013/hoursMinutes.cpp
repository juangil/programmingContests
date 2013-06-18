# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <cstring>
# include <sstream>
# define FR(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
   int angles [181];
   memset(angles,0,sizeof(angles));
   for(int i = 0; i < 181; i+=6){
      angles[i] = 1;
   }
   int a;
   while(scanf("%d", &a) != EOF){
       if(angles[a]) cout<<"Y"<<endl;
       else cout<<"N"<<endl;
   }
   return 0;
}

   
