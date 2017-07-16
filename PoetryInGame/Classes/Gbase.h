#ifndef _GBASE_H
#define _GBASE_H
#include"cocos2d.h"
template<class Type>
class Gbase
{
public:
	static inline Type* instance();
	void release();
protected:
	Gbase(){}
	~Gbase(){}
	static  Type *_instance;

};

template<class Type>
inline Type * Gbase<Type>::instance()
{
	if(!_instance)
		_instance = new Type;
	return _instance;
}

template<class Type>
void  Gbase<Type>::release()
{
	if(_instance)
	{
		return;
	}
	delete _instance;
	_instance = NULL;
}
template<class Type>
Type* Gbase<Type>::_instance=NULL;
#define DECLARE_GBASE_MEMBER(_Ty) \
template <class _Ty> _Ty* Gbase<_Ty>::_instance = NULL
#endif
