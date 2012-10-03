
#include <algorithm>

#include <iostream>
using std::ostream;

template <class at>
class KSArray
{

public:
	typedef at value_type; 
	typedef std::size_t size_type;
	//default constructor
	KSArray();
	//single parameter constructor
	KSArray(size_type theSize);
	//two parameter constructor
	KSArray(value_type param, size_type theSize);
	//copy constructor
	KSArray(const KSArray & toCopy);
	//retrieve the size 
	size_type size();
	//begin iterator
	value_type *begin();
	//constant begin iterator
	const value_type *begin() const;
	//end iterator
	value_type *end();

private:
	value_type * _arrayPtr; // pointer to a value_type
	size_type _arraySize; //hold the array size 
		
};

template <class at>
KSArray<at>::KSArray():_arrayPtr(new value_type[10]) 
{}

template <class at>
KSArray<at>::KSArray(size_type theSize)
	:_arrayPtr(new value_type[theSize]), _arraySize(theSize) 
{}

template <class at>
KSArray<at>::KSArray(value_type val, size_type theSize)
	:_arrayPtr(new value_type[theSize]), _arraySize(theSize)
{
	for(int i=0; i<_arraySize; i++)
	{
		_arrayPtr[i] = val;
	}
}

/*template <class at>
KSArray<at>::KSArray(const KSArray & toCopy)
{

}*/ //we can use std copy for this after we have begin() and end()

template< class at>
typename KSArray<at>::size_type KSArray<at>::size()
{
	return(_arraySize);
}

template< class at>
typename KSArray<at>::value_type * KSArray<at>::begin()
{
	return(_arrayPtr);
}

template< class at>
const typename KSArray<at>::value_type * KSArray<at>::begin() const
{
	return(_arrayPtr);
}//not sure how to check that this works

template< class at>
typename KSArray<at>::value_type * KSArray<at>::end()
{
	return(begin()+_arraySize);
}



