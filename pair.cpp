# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <vector>
# include <utility>
# include <string>

using namespace std;

int compare(const void *a, const void *b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    /*pair<string, pair<int,int> > p ;
    p.first="tenga";
    string s = p.first;
    int x = p.second.first;
    int y = p.second.second;*/
    
    vector< pair<int,int>  > pairs;
    for(int i=20; i>0; i--)
    {
       pairs.push_back(make_pair(i/2,i/5));
    }
    qsort((void*)pairs, 20, sizeof(vector[0]), compare);
    
    //cout<<s<<" "<<x<<" "<<y<<endl;
    return 0;
    
}
