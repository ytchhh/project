#include "bigInt.h"

//大数在线性表中是倒序放置的
BigInt::BigInt(u_long value)
{
    if (value == 0)
        push_back(0);
    else
    {
        while (value > 0) 
        {
            push_back(value%10); 
            value /= 10;
        }
    }
}

BigInt::BigInt()
{
}
BigInt::BigInt(const BigInt &bt)
    :big(bt.big)
{
}
BigInt::~BigInt()
{
    
}

BigInt& BigInt::operator=(const BigInt &bt)
{
    if (&bt != this)
    {
        big = bt.big;
    }
    return *this;
}

BigInt& BigInt::operator=(u_long value)
{
    clear();
    if (value == 0)
        push_back(0);
    else
    {
        while(value != 0)
        {
            push_back(value%10); 
            value /= 10;
        }
    }
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    ++*this;
    return temp;
}
BigInt& BigInt::operator++()
{
    u_char sign = 1;
    size_t i = 1;
    while (sign>0 && i<=size())
    {
        (*this)[i] = AddItem((*this)[i], 0, sign);
        ++i;
    }
    if (sign > 0)
        push_back(sign);
    return *this;
}

void BigInt::LoadData(size_t sz)
{
    srand(time(NULL));
    for (int i = 0; i < sz; ++i)
    {
        push_back(rand()%10);
    }
    clear_head_zero();
}

//倒序放置   必须倒着输出
void BigInt::PrintData() const
{
    for (int i = big.size(); i >= 1; --i) 
    {
        cout << (int)big[i];
    }
    cout << endl;
}

u_char BigInt::back() const
{
    return big.back();
}
void BigInt::pop_back()
{
    big.pop_back();
}

void BigInt::clear()
{
    big.clear();
}

void BigInt::push_back(u_char x)
{
    big.push_back(x);
}
void BigInt::push_front(u_char x)
{
    big.push_front(x);
}

size_t BigInt::size() const
{
    return big.size();
}
void BigInt::clear_head_zero()
{
    while(back() == 0 && size() > 0)
    {
        pop_back();
    }
}
u_char& BigInt::operator[](int pos)
{
    return big[pos];
}
const u_char& BigInt::operator[](int pos) const
{
    return big[pos];
}
bool BigInt::operator<(const BigInt &bt) const
{
    if (size() < bt.size()) 
        return true;
    else if (size() > bt.size())
        return false;
    size_t i = size();
    while (i >= 1)
    {
        if ((*this)[i] < bt[i]) 
            return true;
        else if ((*this)[i] > bt[i])
            return false;
        --i;
    }
    return false;
}

bool BigInt::operator>(const BigInt &bt) const
{
    if (size() > bt.size())
        return true;
    else if (size() < bt.size())
        return false;
    size_t i = size();
    while (i >= 1)
    {
        if ((*this)[i] > bt[i]) 
            return true;
        else if ((*this)[i] < bt[i])
            return false;
        --i;
    }
    return false;
}

bool BigInt::operator>=(const BigInt &bt) const
{
    return !(*this < bt);
}
bool BigInt::operator<=(const BigInt &bt) const
{
    return !(*this > bt);
}

bool BigInt::operator==(const BigInt &bt) const
{
    if (size() != bt.size())
        return false;
    size_t i = 1;
    while (i <= size())
    {
        if ((*this)[i] != bt[i]) 
            return false;
        ++i;
    }
    return true;
}
bool BigInt::operator!=(const BigInt &bt) const
{
    return !(*this == bt);
}

BigInt& BigInt::operator+=(const BigInt &bt)
{
    BigInt temp = *this;
    if (bt != 0)
    {
        Add(temp, *this, bt);
        *this = temp;
    }
    return *this;
}
BigInt& BigInt::operator-=(const BigInt &bt)
{
    BigInt temp = *this;
    if (bt != 0)
    {
        Sub(temp, *this, bt); 
        *this = temp;
        //cout << "tmep = ";
        //temp.PrintData();
        //cout << "*this = ";
        //(*this).PrintData();
    }
    return *this;
}
BigInt& BigInt::operator*=(const BigInt &bt)
{
    BigInt temp = *this;
    if (bt != 0)
    {
        Mul(temp, *this, bt); 
        *this = temp;
    }
    return *this;
}

//sign  传入传出参数
u_char BigInt::AddItem(u_char a, u_char b, u_char &sign)
{
    u_char sum = a + b +sign;
    if (sum >= 10)
    {
        sign = 1;
        sum -= 10;
    }
    else
        sign = 0;
    return sum;
}
void BigInt::Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    bt.clear();
    u_char sum, sign = 0;
    size_t i=1, j=1;
    //cout << "bt1.size() = " << bt1.size() << endl;
    //cout << "bt2.size() = " << bt2.size() << endl;
    while (i <= bt1.size() && j <= bt2.size())
    {
        sum = AddItem(bt1[i], bt2[j], sign); 
        //cout << "sum = " << (int)sum << endl;
        bt.push_back(sum);
        //cout << "i = " << i << endl;
        //cout << "j = " << j << endl;
        ++i;
        ++j;
    }
    while (i<=bt1.size())
    {
        sum = AddItem(bt1[i], 0, sign); 
        bt.push_back(sum);
        //cout << "i = " << i << endl;
        ++i;
    }
    while (j<=bt2.size())
    {
        sum = AddItem(0, bt2[j], sign); 
        bt.push_back(sum);
        //out << "j = " << j << endl;
        ++j;
    }
    if (sign > 0)
        bt.push_back(sign);
    bt.clear_head_zero();
}

u_char BigInt::SubItem(u_char a, u_char b, u_char &sign)
{
    u_char sub;
    if (a >= b+sign)
    {
        sub = a - b - sign;
        sign = 0;
    }
    else
    {
        sub = a + 10 - b - sign;
        sign = 1;
    }
    return sub;
}
void BigInt::Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    if (bt1 < bt2)
        return ;
    if (bt1 == bt2)
        bt = 0;
    
    bt.clear();
    u_char sub, sign = 0;
    size_t i = 1, j = 1;
    while (i<=bt1.size() && j<=bt2.size())
    {
        sub = SubItem(bt1[i], bt2[j], sign); 
        bt.push_back(sub);
        ++i;
        ++j;
    }
    while (i<=bt1.size())
    {
        sub = SubItem(bt1[i], 0, sign); 
        bt.push_back(sub);
        ++i;
    }
    bt.clear_head_zero();
}

//将大数bt1与一位数x相乘
void BigInt::MulItem(BigInt &bt, const BigInt &bt1, u_char x)
{
    u_char mul, sign = 0;
    size_t i = 1;
    while (i <= bt1.size())
    {
        mul = bt1[i] * x + sign;
        if (mul >= 10)
        {
            sign = mul / 10;
            mul = mul % 10;
        }
        else
            sign = 0;
        bt.push_back(mul);
        ++i;
    }
    if (sign > 0)
        bt.push_back(sign);
}
//错位相加，用来模拟手算乘法
void BigInt::AddMove(BigInt &bt, const BigInt &bt1, int offset)
{
    u_char sign = 0;
    size_t j = 1;
    size_t i = offset;
    while (i<=bt.size() && j<=bt1.size())
    {
        bt[i] = AddItem(bt[i], bt1[j], sign);
        ++i;
        ++j;
    }
    while (i <= bt.size())
    {
        bt[i] = AddItem(bt[i], 0, sign);
        ++i;
    }
    while (j <= bt1.size())
    {
        u_char sum = AddItem(0, bt1[j], sign); 
        bt.push_back(sum);
        ++j;
    }
    if (sign > 0)
        bt.push_back(sign);
}

void BigInt::Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    bt = 0;
    BigInt tmp;
    for (size_t i = 1; i <= bt2.size(); ++i)
    {
        tmp.clear();
        MulItem(tmp, bt1, bt2[i]);
        AddMove(bt, tmp, i);
        //cout << "bt = ";
        //bt.PrintData();
        //cout << "bt1 = ";
        //bt1.PrintData();
        //cout << "bt2 = ";
        //bt2.PrintData();
        //cout << "tmp = ";
        //tmp.PrintData();
    }
}

void BigInt::Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    assert(bt2 != 0); 
    bt.clear();
    if (bt1 < bt2)
        bt = 0;
    else if (bt1 == bt2)
        bt = 1;
    else
    {
        size_t bt1_len = bt1.size();
        size_t bt2_len = bt2.size();
        int k = bt1_len - bt2_len;

        BigInt btd;
        btd.clear();
        for (size_t i = 1; i <= bt2.size(); ++i)
        {
            btd.push_back(bt1[i+k]); 
        }
        u_char div = 0;
        while (k >= 0)
        {
            while (btd >= bt2) 
            {
                btd -= bt2;
                div ++;
                btd.clear_head_zero();
            }
            bt.push_front(div);
            div = 0;
            if (k > 0)
                btd.push_front(bt1[k]);
            --k;
            btd.clear_head_zero();
        }
        bt.clear_head_zero();
    }
}
void BigInt::Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    assert(bt2 != 0); 
    bt.clear();
    if (bt1 < bt2)
        bt = bt1;
    else if (bt1 == bt2)
        bt = 0;
    else
    {
        size_t bt1_len = bt1.size();
        size_t bt2_len = bt2.size();
        int k = bt1_len - bt2_len;

        BigInt btd;
        btd.clear();
        for (size_t i = 1; i <= bt2.size(); ++i)
        {
            btd.push_back(bt1[i+k]); 
        }
        while (k >= 0)
        {
            while (btd >= bt2) 
            {
                btd -= bt2;
                btd.clear_head_zero();
            }
            if (k > 0)
                btd.push_front(bt1[k]);
            --k;
            btd.clear_head_zero();
        }
        bt = btd;
        bt.clear_head_zero();
    }
}

void BigInt::Squate(BigInt &bt, const BigInt &bt1)
{
    BigInt::Mul(bt, bt1, bt1);
}
void BigInt::Power(BigInt &bt, const BigInt &bt1, u_long n)
{
    assert(n >= 0);
    bt = 1;
    for (u_long i = 0; i < n; ++i)
        bt *= bt1;
}
void BigInt::Power(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
    assert(bt2 >= 0);
    bt = 1;
    for (BigInt i = 0; i < bt2; ++i)
        bt *= bt1;
}
void BigInt::PowMod(BigInt &bt, const BigInt &a, const BigInt &b, const BigInt &n)
{
    assert(b >= 0 && n >= 0);
    BigInt tmp;
    BigInt::Power(tmp, a, b);
    BigInt::Mod(bt, tmp, n);
}



