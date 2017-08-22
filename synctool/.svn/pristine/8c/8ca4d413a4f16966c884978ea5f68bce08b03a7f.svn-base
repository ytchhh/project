#include "configparser.h"

#include <iostream>
using namespace std;

extern ConfigParser* sparser;
int main()
{
    sparser->initkvmap("lasync.conf");
    sparser->dump();

    int ret = sparser->haskey("port");
    cout << ret << endl;

    string value;

    ret = sparser->getvalue("sharedir", value);
    cout << "ret: " << ret
        <<" sharedir:" << value << endl;

    ret = sparser->getvalue("newkey", value);
    cout << "ret: " << ret
        <<" newkey:" << value << endl;

    return 0;
}
