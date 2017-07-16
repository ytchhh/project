#ifndef SEQLIST_H
#define SEQLIST_H

#include "utility.h"

#define MALLOCFAILED 1


template <class Type>
class SeqList
{
public:
    typedef Type& reference;
    typedef const Type& const_reference;
private:
	enum{DEFAULT_SIZE = 10, INC_SIZE = 5};
	Type *base;
	size_t capacity;
	size_t len;

public:
	SeqList(unsigned sz = DEFAULT_SIZE)
	{
		capacity = sz >= DEFAULT_SIZE ? sz : DEFAULT_SIZE;	
		base = new Type[capacity+1];
		assert(base != NULL);
        memset(base, 0, sizeof(Type)*(capacity+1));
		len = 0;	
	}
	~SeqList()
	{
		capacity = 0;
		delete []base;
		len = 0;
	}
	
public:
	void push_back(const Type &x);
	void push_front(const Type &x);
    void pop_back();
    void pop_front();
    reference back();
    const_reference back() const;
    reference front();
    const_reference front() const;
    void clear();
    void sort();
    void reverse();
    size_t size() const;
    int find(const Type &key) const;
    void erase(const Type &key);

    int getLen() {return len;}
    int getCapacity() {return capacity;}


    reference operator[](int index);
    const_reference operator[](int index) const;

	void show();
    SeqList(const SeqList<Type> &);
    SeqList<Type>& operator=(const SeqList<Type> &);
protected:
	bool more_capacity();


};

#endif

template<class Type>
SeqList<Type>::SeqList(const SeqList<Type> &list)
{
    capacity = list.capacity;
    base = new Type[capacity+1];
    memset(base, 0, sizeof(Type) * (capacity+1));
    memcpy(base, list.base, sizeof(Type)*(list.len+1));
    len = list.len;
}
template<class Type>
SeqList<Type>& SeqList<Type>::operator=(const SeqList<Type> &list)
{
    //考虑异常安全的做法
    if (&list != this)
    {
        SeqList<Type> tempList(list);
        Type *tempBase = tempList.base;
        tempList.base = base;
        base = tempBase;
        capacity = list.capacity;
        len = list.len;
    }
    return *this;
}


template <class Type>
typename SeqList<Type>::reference SeqList<Type>::back()
{return base[len];}
template <class Type>
typename SeqList<Type>::const_reference SeqList<Type>::back() const 
{return base[len];}

template <class Type>
typename SeqList<Type>::reference SeqList<Type>::front()
{return base[1];}
template <class Type>
typename SeqList<Type>::const_reference SeqList<Type>::front() const 
{return base[1];}

template <class Type>
void SeqList<Type>::clear()
{len = 0;}

template <class Type>
size_t SeqList<Type>::size() const
{return len;}

template <class Type>
typename SeqList<Type>::reference SeqList<Type>::operator[](int index)
{
    //cout << "index = " << index << endl;
    //cout << "len = " << len << endl;
    assert(index >= 1 && index <= len);
    return base[index];
}

template <class Type>
typename SeqList<Type>::const_reference SeqList<Type>::operator[](int index) const
{
    //cout << index << endl;
    //cout << len << endl;
    assert(index >= 1 && index <= len);
    return base[index];
}

template <class Type>
void SeqList<Type>::sort()
{
    if (len <= 1)
        return ;
    for (int i = 0; i < len-1; ++i)
        for(int j = 0; j <= len-i-1; ++j)
        {
            if (base[j] > base[j+1]) 
            {
                Type temp = base[j]; 
                base[j] = base[j+1];
                base[j+1] = temp;
            }
        }
}

template <class Type>
void SeqList<Type>::reverse()
{
    if (len <= 1)
        return ;
    int i = 0;
    while (i<(len+1)/2)
    {
        Type temp = base[1+i];
        base[1+i] = base[len-i];
        base[len-i] = temp;
        ++i;
    }
}

template <class Type>
int SeqList<Type>::find(const Type& key) const 
{
    for (int i = 1; i <= len; ++i)
    {
        if (key == base[i]) 
            return i;
    }
    return -1;
}

template <class Type>
void SeqList<Type>::erase(const Type &key)
{
    int pos = find(key);
    if (pos == -1)
        return ;
    for (int i = pos; i < len; ++i)
        base[i] = base[i+1];
    --len;
}




template <class Type>
bool SeqList<Type>::more_capacity()
{
    capacity += INC_SIZE;
    Type *new_base = new Type[capacity+1];
	assert(new_base != NULL);
    memset(new_base, 0, sizeof(Type)*(capacity+1));
	memmove(new_base, base, sizeof(Type)*(len+1));
	delete []base;
	base = new_base;
	return true;
}

template <class Type>
void SeqList<Type>::push_back(const Type &x)
{
    if (len >= capacity && !more_capacity())
    {
        cout << "Out of Memory." << endl; 
        return ;
    }
    base[++len] = x;
}



template <class Type>
void SeqList<Type>::push_front(const Type &x)
{
    if (len >= capacity && !more_capacity())
    {
        cout << "Out Of Memory." << endl; 
        return ;
    }
    for (int i = ++len; i > 1; --i)
    {
        base[i]  = base[i-1];
    }
    base[1] = x;
}

template <class Type>
void SeqList<Type>::pop_back()
{
    assert(len > 0);
    --len;
}

template <class Type>
void SeqList<Type>::pop_front()
{
    assert(len > 0);
    int i = 0; 
    while (++i < len)
    {
        base[i] = base[i+1];
    }
    --len;
}


template <class Type>
void SeqList<Type>::show()
{
		for (int i = 0; i <= len; ++i)	
		{
				cout << base[i] << " ";
		}
		cout << endl;
		cout << "capacity = " << capacity << " " << "len = " << len << " " << endl;
}
