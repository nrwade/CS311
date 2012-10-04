#ifndef KSARRAY_H
#define KSARRAY_H

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
	KSArray(size_type theSize, value_type val);
	//copy constructor
	KSArray(const KSArray & toCopy);
	//retrieve the size 
	size_type size() const;
	//begin iterator
	value_type *begin();
	//constant begin iterator
	const value_type *begin() const;
	//end iterator
	value_type *end();
	//constant end iterator
	const value_type *end() const;
	//destructor
	~KSArray();
	//bracket operator
	value_type & operator [] (size_type index);
	//costant bracket operator
	const value_type & operator [] (size_type index) const;
	//overloaded = operator
	KSArray & operator=(const KSArray & rhs);

private:
	value_type * _arrayPtr; // pointer to a value_type
	size_type _arraySize; //hold the array size 
		
};

template <class at>
KSArray<at>::KSArray():_arrayPtr(new value_type[10]), _arraySize(10)
{}

template <class at>
KSArray<at>::KSArray(size_type theSize)
	:_arrayPtr(new value_type[theSize]), _arraySize(theSize) 
{}

template <class at>
KSArray<at>::KSArray( size_type theSize, value_type val)
	:_arrayPtr(new value_type[theSize]), _arraySize(theSize)
{
	for(int i=0; i<_arraySize; i++)
	{
		_arrayPtr[i] = val;
	}
}


//copy constructor
template< class at>
KSArray<at>::KSArray(const KSArray & toCopy)
	:_arrayPtr(new value_type[toCopy.size()]), _arraySize(toCopy.size()) 
{
	std::copy(toCopy.begin(), toCopy.end(), _arrayPtr);
} 

template< class at>
typename KSArray<at>::size_type KSArray<at>::size() const
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

template< class at>
const typename KSArray<at>::value_type * KSArray<at>::end() const
{	
	return(begin()+_arraySize);
}

//destructor
template<class at>
KSArray<at>::~KSArray()
{
	delete [] _arrayPtr;
}

template <class at>
 typename KSArray<at>::value_type & KSArray<at>::operator [] (typename KSArray::size_type index)
 {
 	if (0 <= index < _arraySize)
 	{
 	return (_arrayPtr[index]);//following the example, but does this actually return a reference?
 	}
 }

 template <class at>
 const typename KSArray<at>::value_type & KSArray<at>::operator [] (typename KSArray::size_type index) const
 {
 	if (0 <= index < _arraySize)
 	{
 	return (_arrayPtr[index]);//following the example, but does this actually return a reference?
 	}
 }

template <class at>
KSArray<at> & KSArray<at>::operator=(const KSArray<at> & rhs)
{
	if (this != &rhs)
	{
		delete [] _arrayPtr;
		_arrayPtr = new value_type[rhs.size()]; 
		_arraySize = rhs.size(); 
		std::copy(rhs.begin(), rhs.end(), _arrayPtr);
	}
	return *this;
}

template <class at> 
bool operator==(const KSArray<at>& lhs, const KSArray<at>& rhs)
{	
	
	if (lhs.size() != rhs.size())
		return false;

	int i = 0;

	while (i < lhs.size())
	{
		if (lhs[i] != rhs[i])
			return false;

		i++;
	}

	return true;
}

template <class at> 
bool operator != (const KSArray<at>& lhs, const KSArray<at>& rhs)
{
	return(! (lhs==rhs) );
}

template <class at>
bool operator<(const KSArray<at>& lhs, const KSArray<at>& rhs)
{

	if (lhs == rhs)
		return false;

	for(int i=0; i<lhs.size(); i++)
	{
		if (i > rhs.size()-1) 
		{
			return false;
		}

		if (lhs[i] < rhs[i]) 
		{
			return true;
		}  
		else if (lhs[i]> rhs[i]) 
		{ 
			return false;
		}


	} 

	if (rhs.size() > lhs.size()) 
	{
		return true;
	}


	return false;

	/*for(int i=0; i<lhs.size(); i++)
	{
			if (lhs[i] > rhs[i])
				return false;
 
			if (lhs[i] < rhs[i])
				return true;

	} */
	//if we've made it this far and have run out of values on the right hand side
	// the rhs must be smaller so we return false.
	//return false;

	/*bool comp=false;

	for (int i=0; i<lhs.size(); i++)
	{
		if (lhs[i] < rhs[i])
		{
			comp = true;
		}
		else comp = false;
	}

	return comp;*/
}

template <class at>
bool operator<=(const KSArray<at>& lhs, const KSArray<at>& rhs)
{
	return(!(rhs<lhs));
}

template <class at>
bool operator>(const KSArray<at>& lhs, const KSArray<at>& rhs)
{
	return(!(lhs<=rhs));
}

template <class at>
bool operator>=(const KSArray<at>& lhs, const KSArray<at>& rhs)
{
	return(!(lhs<rhs));
}

//KSARRAY_H
#endif  
