#ifndef BIGINT_H
#define BIGINT_H

#include "utility.h"
#include "seqlist.h"

class BigInt
{
public:
	BigInt(u_long value);
    BigInt();
    BigInt& operator=(u_long value);
	~BigInt();
    BigInt(const BigInt &bt);

public:
	void LoadData(size_t sz);
    bool addItem(u_char c);
    u_char toUChar(unsigned i);
	void PrintData() const;
    void push_back(u_char x);
    void push_front(u_char x);
    u_char back() const;
    void clear();
    void pop_back();
    size_t size() const;
    void clear_head_zero();

public:
    static u_char AddItem(u_char a, u_char b, u_char &sign);
    static u_char SubItem(u_char a, u_char b, u_char &sign);

public:
    static void Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Squate(BigInt &bt, const BigInt &bt1);
    static void Power(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
    static void Power(BigInt &bt, const BigInt &bt1, u_long n);
    static void PowMod(BigInt &bt, const BigInt &bt1, const BigInt &bt2, const BigInt &bt3);

public:
    static void MulItem(BigInt &bt, const BigInt &bt1, u_char x);
    static void AddMove(BigInt &bt, const BigInt &bt1, int offset);

public:
    bool operator<(const BigInt &bt) const ;
    bool operator>(const BigInt &bt) const;
    bool operator<=(const BigInt &bt) const;
    bool operator>=(const BigInt &bt) const;
    bool operator==(const BigInt &bt) const;
    bool operator!=(const BigInt &bt) const;

public:
    BigInt& operator++();
    BigInt operator++(int);
    BigInt& operator--();
    BigInt& operator--(int);

public:
    BigInt& operator+=(const BigInt &bt);
    BigInt& operator-=(const BigInt &bt);
    BigInt& operator*=(const BigInt &bt);
    BigInt& operator/=(const BigInt &bt);
    BigInt& operator%=(const BigInt &bt);

public:
    u_char& operator[](int pos);
    const u_char& operator[](int pos) const;

public:
    BigInt operator+(const BigInt &bt);
    BigInt operator-(const BigInt &bt);
    BigInt operator*(const BigInt &bt);
    BigInt operator/(const BigInt &bt);
    BigInt operator%(const BigInt &bt);
    BigInt& operator=(const BigInt &bt);
private:
    SeqList<u_char> big;
};
#endif
