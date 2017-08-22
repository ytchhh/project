#include <iostream>
using namespace std;

#include "../lib/nfsutils.h"

int main()
{
    int ret = 0;

    ret = nfsstart();
    cout << "start nfs: " << ret << endl;

    ret = nfsstatus();
    cout << "status nfs: " << ret << endl;

    ret = nfsstop();
    cout << "stop nfs: " << ret << endl;

    ret = nfsstatus();
    cout << "status nfs: " << ret << endl;

    return 0;
}
