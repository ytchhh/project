#include <iostream>
using namespace std;

#include "../lib/strutils.h"

int main()
{
    int ret = 0;
    ret = startswith("this is a test", "this");
    cout << "test startswith = " << ret << endl;

    ret = endswith("this is a test", "test");
    cout << "test endswith = " << ret << endl;


    string input("a,b,c,dddd,e,f");
    string sep(",");
    vector<string> out;
    ret = split(input, sep, out);
	int i;
	for(i = 0; i < out.size(); ++i)
		cout<<out[i]<<" ";
	cout<<endl;
    cout << "test split" << endl;

	string joinedstr;
    ret = join(out, sep, joinedstr);

    cout << "test join" << endl;
	cout << joinedstr <<endl;
    return 0;
}
