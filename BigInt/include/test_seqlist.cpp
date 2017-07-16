#include "seqlist.h"

int main(void)
{
    SeqList<char> mylist;
    mylist.push_back('x');
    mylist.push_back('y');
    mylist.push_back('z');
    mylist.show();

    SeqList<char> mylist2;
    mylist2.push_back('a');
    mylist2.push_back('b');
    mylist2.push_back('c');
    mylist2.show();

    mylist2 = mylist;
    mylist2.show();
    mylist.show();

    return 0;
}
