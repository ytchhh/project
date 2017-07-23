#include"BigInt.h"

BigInt::BigInt()			//构造函数
{
}

BigInt::BigInt(long value)			//带参构造函数,里面的数据必须倒着存放。
{
	if(value < 0)
	{
		value = abs(value);
		de.push_back('-');
	}
	else
		de.push_back('+');
	do
	{
		de.push_back(value%10);
		value /= 10;
	}while(value);
}

BigInt::BigInt(string &str)		//字符串构造函数
{
	int i;
	if(str[0] == '-')
	{
		i = 1;
		while(str[i] != '\0')
		{
			de.push_front(str[i]);
			++i;
		}
		de.push_front('-');
	}
	else
	{
		i = 0;
		while(str[i] != '\0')
		{
			de.push_front(str[i]);
			++i;
		}
		de.push_front('+');
	}
}

BigInt::BigInt(const BigInt& bt):de(bt.de)			//拷贝构造函数
{
}

BigInt& BigInt::operator=(const BigInt& bt)	//赋值构造函数
{
	if(&bt != this)
		de = bt.de;
	return *this;
}

BigInt::~BigInt()			//析构函数
{
}


void BigInt::clear()		//清楚函数
{
	de.clear();
}

void BigInt::show()			//打印函数
{
	cout<<de[0];
	deque<char>::iterator it = de.end();
	if(de.size() >= 3 && (de.back() == 0 || de.back() == '0'))
	{
		int j = 0;
		while(*it == 0 || *it == '0')
		{
			j++;
			it--;
		}
		j--;
		if(de[1] < 10)
		{
			for(int i = de.size()-j; i > 1; --i)
				if(de[i-1] != 0)
					cout<<(int)de[i-1];
		}
		else
		{
			for(int i = de.size()-j; i > 1; --i)
				cout<<(char)de[i-1];
		}
		cout<<endl;
	}
	else
	{
		if(de[1] < 10)
		{
			for(int i = de.size(); i > 1; --i)
				cout<<(int)de[i-1];
		}
		else
		{
			for(int i = de.size(); i > 1; --i)
				cout<<(char)de[i-1];
		}
		cout<<endl;
	}
}

void BigInt::push_back(char element)	//尾插
{
	de.push_back(element);
}

void BigInt::push_front(char element)	//头插
{
	de.push_front(element);
}

size_t BigInt::size()const					//求个数
{
	return de.size();
}

char& BigInt::operator[](int position)	//重载[]
{
	return de[position];
}

const char& BigInt::operator[](int position)const
{
	return de[position];
}

bool BigInt::operator==(const BigInt &bt)const	//重载==
{
	if(size() != bt.size())
		return false;
	size_t i = 1;
	while(i < size())
	{
		if((*this)[i] != bt[i])
			return false;
		++i;
	}
	return true;
}

bool BigInt::operator>(const BigInt &bt)const	//重载>
{
	if(size() > bt.size())
		return true;
	else if(size() < bt.size())
		return false;
	size_t i = size()-1;
	while(i >= 1)
	{
		if((*this)[i] > bt[i])
			return true;
		else if((*this)[i] < bt[i])
			return false;
		--i;
	}
	return false;
}

bool BigInt::operator<(const BigInt &bt)const	//重载<
{
	if(size() < bt.size() )
		return true;
	else if(size() > bt.size())
		return false;
	size_t i = size()-1;
	while(i >= 1)
	{
		if((*this)[i] < bt[i])
			return true;
		else if((*this)[i] > bt[i])
			return false;
		--i;
	}
	return false;
}

char BigInt::AddItem(char a,char b,char& sign)	//每个位相加
{
	char sum = a + b + sign - 96;	//加上进位的sign
	if(sum >= 10)			//需要进位
	{
		sum -= 10;
		sign = 1;
	}
	else					//不需要进位
		sign = 0;
	return sum + 48;
}

void BigInt::Add(BigInt &bt,BigInt &bt1,BigInt &bt2)	//加法
{
	size_t i = 1,j = 1;
	bt.clear();
	char sum,sign = 0;			//sign来判断是否需要进位
	if(bt1[0] == bt2[0])		//两个数的符号相同，同为+或同为-
	{
		bt.push_back(bt1[0]);
		while(i < bt1.size() && j < bt2.size())	//把相同位的相加
		{
			sum = AddItem(bt1[i],bt2[j],sign);
			bt.push_back(sum);
			++i;
			++j;
		}
		while(i < bt1.size())				//把bt1多余的位补上
		{
			sum = AddItem(bt1[i],'0',sign);
			bt.push_back(sum);
			++i;
		}
		while(j < bt2.size())				//把bt2多余的位补上
		{
			sum = AddItem('0',bt2[j],sign);
			bt.push_back(sum);
			++j;
		}
		if(sign > 0)
			bt.push_back('1');
	}
	else 
	{
		if(bt1[0] == '+' && bt2[0] == '-')
		{
			BigInt temp = bt2;
			temp[0]= '+';
			Sub(bt,bt1,temp);
		}
		else if(bt1[0] == '-' && bt2[0] == '+')
		{
			BigInt temp = bt1;
			temp[0] = '+';
			Sub(bt,bt2,temp);
		}
	}
}

char BigInt::SubItem(char a,char b,char& sign)					//单个位相减
{
	char sub;
	if(a >= b+sign)				//不需要借位
	{
		sub = (a -48) - (b-48) - sign;
		sign = 0;
	}
	else						//需要借位
	{
		sub = (a - 48) + 10 - (b - 48) -sign;
		sign = 1;
	}
	return sub + 48;
}

void BigInt::Sub(BigInt &bt,BigInt &bt1,BigInt &bt2)			//减法 bt = bt1-bt2
{
	size_t i = 1,j = 1;
	bt.clear();
	char sub,sign = 0;

	if(bt1[0] == '+' && bt2[0] == '+')			//bt1和bt2都为正数
	{
		if(bt1 == bt2)							//两个数相等
			bt = BigInt(0);
		else if(bt1 > bt2)						//bt1大于bt2
		{
			while(i < bt1.size() && j < bt2.size())
			{
				sub = SubItem(bt1[i],bt2[j],sign);
				bt.push_back(sub);
				++i;
				++j;
			}
			while(i < bt1.size())
			{
				sub = SubItem(bt1[i],'0',sign);
				bt.push_back(sub);
				++i;
			}
			bt.push_front('+');
		}
		else if(bt1 < bt2)						//bt1小于bt2
		{
			BigInt tmp = bt1;
			Sub(bt,bt2,tmp);
			bt[0] = '-';
		}
	}
	else if(bt1[0] == '-' && bt2[0] == '-')
	{
		BigInt temp1 = bt1,temp2 = bt2;
		temp1[0] = '+';
		temp2[0] = '+';
		if(bt1 == bt2)
			bt = 0;
		else if(bt1 > bt2)						//bt1大于bt2
		{
			Sub(bt,temp1,temp2);
			bt.push_front('-');
		}
		else if(bt1 < bt2)
		{
			Sub(bt,temp2,temp1);
			bt.push_front('+');
		}
	}
	else if(bt1[0] == '+' && bt2[0] == '-')
	{
		BigInt temp = bt2;
		temp[0] = '+';
		Add(bt,bt1,temp);
	}
	else if(bt1[0] == '-' && bt2[0] == '+')
	{
		BigInt temp = bt2;
		temp[0] = '-';
		Sub(bt,bt1,temp);
	}
}

