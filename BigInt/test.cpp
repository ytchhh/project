#include "include/bigInt.h"

int main(void)
{
    BigInt bt1;
    BigInt bt2;
    BigInt bt3;
    BigInt bt4;
    BigInt bt5;
    BigInt bt6;
    BigInt bt7;
    bt1.LoadData(6);
    bt1.PrintData();
    sleep(1);
    bt2.LoadData(5);
    bt2.PrintData();

    BigInt::Add(bt3, bt1, bt2);
    bt3.PrintData();
    bt3 -= bt2;
    bt3.PrintData();
    BigInt::Sub(bt4, bt3, bt1);
    bt4.PrintData();
    BigInt::Mul(bt5, bt1, bt2);
    bt5.PrintData();
    BigInt::Div(bt6, bt1, bt2);
    bt6.PrintData();
    BigInt::Mod(bt7, bt1, bt2);
    bt7.PrintData();
    BigInt::Squate(bt7, bt1);
    bt7.PrintData();
    BigInt::Power(bt7, bt1, 2);
    bt7.PrintData();
    BigInt::Power(bt7, bt1, bt2);
    bt7.PrintData();

    return 0;
    
}
/*

int main(void)
{
    BigInt bt1(1234);
    BigInt bt2(11);
    BigInt bt3;
    BigInt::Div(bt3, bt1, bt2);
    cout << "bt3 = ";
    bt3.PrintData();
    return 0;
}
*/
