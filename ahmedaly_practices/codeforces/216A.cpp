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


int main()
{
    int a,b,c;
    cin >>  a >> b >> c;
    int result = a*b*c - ((a-1)*(b-1)*(c-1));
    cout<<result<<endl;
    return 0;
}
