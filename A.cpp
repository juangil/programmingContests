# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <string>

using namespace std;


string presidents [40] = {"Washington",
"Adams",
"Jefferson",
"Madison"	 ,
"Monroe"	 , 
"Adams",
"Jackson"	, 
"Van Buren",	 
"Harrison",	 
"Tyler"	 ,
"Polk"	 ,
"Taylor"	 ,
"Fillmore"	 ,
"Pierce"	,
"Buchanan",
"Lincoln",
"Johnson",
"Grant",
"Hayes",
"Garfield",
"Arthur",
"Cleveland",
"Harrison",
"Cleveland",
"McKinley",
"Roosevelt"	 ,
"Taft"	 ,
"Wilson"	 ,
"Harding",	 
"Coolidge",
"Hoover"	,
"Roosevelt",
"Truman"	 ,
"Eisenhower"	,
"Kennedy",
"Johnson",
"Nixon",
"Ford",
"Carter",
"Reagan",
};

int main()
{
   int n;
   cin >> n;
   cout << presidents[n-1]<<endl;
   return 0;
}
   
