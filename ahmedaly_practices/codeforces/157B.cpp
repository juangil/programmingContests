# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <vector>
# include <algorithm>
# include <map>
# include <string>
# include <sstream>
# define PI 3.1415926535897931



using namespace std;



bool myfunction (int i,int j) { return (i>j); }
vector<int> v;
int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
       int r;
       cin >> r;       
       v.push_back(r);
    }
    sort(v.begin(), v.end(), myfunction);
    
    double area = 0.0;
    for(int i = 0; i < v.size(); ++i)
    {
       //cout<<v[i]<<endl;
       if(i%2 == 0)
         area += PI*v[i]*v[i];
       else
         area -= PI*v[i]*v[i];
    }
    printf("%lf\n", area);
    return 0;
}
       
       
