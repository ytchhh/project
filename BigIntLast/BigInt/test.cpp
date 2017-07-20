#include"BigInt.h"

int main()
{
	/*
	long value1;
	cout<<"please input data:";
	cin>>value1;
	BigInt bg1(value1);
	long value2;
	cout<<"please input data:";
	cin>>value2;
	BigInt bg2(value2);
	bg1.show();
	bg2.show();
	BigInt bg3 = bg2;
	bg3.show();
	BigInt bg4;
	bg4 = bg2;
	bg4.show();
	*/
	
	/*
	string str1;
	cout<<"please input data:";
	cin>>str1;
	BigInt bg1(str1);
	string str2;
	cout<<"please input data:";
	cin>>str2;
	BigInt bg2(str2);
	bg1.show();
	bg2.show();
	*/
	//189654332887744
	//-9876543247788999
	string str1;
	cout<<"please input data:";
	cin>>str1;
	BigInt bt1(str1);
	string str2;
	cout<<"please input data:";
	cin>>str2;
	BigInt bt2(str2);
	BigInt bt3;
	BigInt::Add(bt3,bt1,bt2);
	bt1.show();
	cout<<"+"<<endl;
	bt2.show();
	bt3.show();
	BigInt bt4;
	BigInt::Sub(bt4,bt1,bt2);
	bt4.show();
	return 0;
}
