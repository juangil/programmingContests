# include <cstdlib>
# include <cstdio>
# include <cmath>
# include <vector>
# include <iostream>

using namespace std;

vector<double> lnn;

int main()
{
   int t;
   lnn.push_back(0.0);
   for(int j = 1; j <= 1000000; j++)
		lnn.push_back(log(j) + lnn[j - 1]);


   scanf("%d", &t);
   for(int i = 0; i < t; i++)
   {
	  int n, b;
	  scanf("%d %d", &n, &b);
	  //cout<<lnn[n]/log(b)<<endl;
	  printf("Case %d: %d\n", i+1, (int)(lnn[n]/log(b)) + 1);
   }
   return 0;
}
