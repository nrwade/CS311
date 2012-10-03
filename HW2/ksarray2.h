#ifndef KSARRAY_H
#define KSARRAY_H

#include <algorithm>

// Write class invariants
// Write pre and post conditions AND requirements on types for all templates

//No resource leaks!

//Document ownership and related issues


//AType is the type of all the items stored in the container
template <typename AType> 
class KSArray
{
public:
	typedef AType value_type; 
	// typedef allows us to use the template parameter outside of the class definition
	// this lets us say "value_type" when we mean the type of the items in the container

	typedef std::size_t size_type;
	//the type of the size of the array
	//I don't really understand why we need this... humph

	//default constructor
	KSArray();
	
	//constructor 1-parameter
	KSArray(size_type numItems);

	//constructor 2-parameter
	KSArray(size_type numItems, value_type val);

	//copy constructor
	KSArray(const KSArray & toCopy);

	size_type size();

	value_type *begin();
	const value_type *begin() const;

	value_type *end();
	const value_type *end() const;

	~KSArray();

	value_type & operator [] (size_type index);
	const value_type & operator [] (size_type index) const;
//need to make a friend copy assignment

private:
	value_type * _arrayPtr; // pointer to a value_type
		
};



//default constructor
KSArray::KSArray():_arrayPtr(new value_type[10])
{}
// should create a KSArray of size 10
	// all items in the array should be default constructed 
	
	//constructor 1-parameter
KSArray::KSArray(size_type numItems)//:_arrayPtr(new value_type[numItems])
{
}
	// parameter is a non-negative integer giving the number of items in the array
	// all items in the array should be default constructed
	//may not create any new implicit type conversions

	//constructor 2-parameter

KSArray::KSArray(size_type numItems, value_type val)//:_arrayPtr(new value_type[numItems])
{

	//use our iterators begin and end to loop through and set each item in the array to val
	/*for(value_type * iter=begin(); iter<=end(); iter++)//do I need to put KSArray.begin() and end? <= or < end
	{
		*iter=val; //we dereference the pointer and set it to val
	}*/
}
	// first parameter is a non-negative integer giving the number of items in the array
	// second parameter is an item of the value type- each item in the array should be set to this value

//copy constructor
KSArray::KSArray(const KSArray & toCopy)
	//:_arrayPtr(new value_type[toCopy.size()]) 
	{
		//std::copy(toCopy.begin(), toCopy.end(), _arrayPtr);

	}
	// must take a const 
	// creates a new object


//operator=
//WRITE THIS!	
	// sets an existing object equal to a copy of some other existing object
// check for self-assignment. If this is not self-assignment, deallocate the old array nd then do essentially what the copy ctor does
// return the object assigned. See slide 11 for sample code


size_type KSArray::size()	//returns the number of items in the array
{
	size_type count=0;
	/*for (value_type * iter=begin(); iter<=end(); iter++)
	{
		count +=count;
	}*/
	return(count);
}


// the two functions should be essentially identical except for the const at the end of the first line
// and the return method
// or we may use the const_cast trick to call the const version from the non-const version
value_type * KSArray::begin()
{
	return(_arrayPtr);
}

value_type * KSArray::end()
{
	value_type holder;
	return(holder);//plus one because we need one past the end
}
//I think I'm doing a type conversion here that I shouldn't be
//ksarray.h:151: error: invalid operands of types ‘double*’ and ‘double’ to binary ‘operator+’

const value_type *KSArray::end() const
{
	const value_type * holder;
	return(holder);
}
	// returns an iterator to just past the last array item- can be a pointer
	// add a number to the return value of begin- what number? size()
	// returns the address of the item one-past the end of the array (think iterator)

//destructor
KSArray::~KSArray()
{
	//delete _arrayPtr;
}
	// deallocate all memory- aka delete all pointers!
 
bool KSArray::operator==(const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{	
	bool comp = false;

	/*if (lhs.value_type == rhs.value_type && lhs.size() == rhs.size())
	{
		for (typename KSArray<AType>::value_type * iter=lhs.begin(); iter<=lhs.end(); iter++)
		{
			if (lhs._arrayPtr+iter == rhs._arrayPtr+iter)
				{
					comp=true;
				}
			else
			{
				comp=false;
			}
		}
	}

	return(lhs.value_type == rhs.value_type && lhs.size() == rhs.size() && comp);*/
	return comp;

}


// two KSArray with the same value type are equal if they have the same size and their corresponding 
// items are all equal.
// Two KSArrays with differnt value types cannot be compared
// Does this need to be a friend to the class?

bool KSArray::operator != (const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{
	//return(! (lhs==rhs) );
	return false;
}
// two KSArray with the same value type are equal if they have the same size and their corresponding 
// items are all equal.
// Two KSArrays with different value types cannot be compared 

bool KSArray::operator<(const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{
	bool comp=false;

	/*if (lhs.value_type == rhs.value_type)
	{
		for(typename KSArray<AType>::value_type * iter=lhs.begin(); iter <= lhs.end(); iter++)
		{
			if (lhs._arrayPtr < rhs._arrayPtr)
			{
				comp=true;
			}
			else
			{
				comp=false;
			}
		}
	}*/
	return comp;
}



//So if we just us == and < and those are templates, do these need to be templates?
bool KSArray::operator<=(const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{
	//return(!(rhs<lhs));
	return false;
}


bool KSArray::operator>(const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{
	//return(!(lhs<=rhs));
	return false;
}

bool KSArray::operator>=(const KSArray<AType>& lhs, const KSArray<AType>& rhs)
{
	//return(!(lhs<rhs));
	return false;
}
//check that all of the operators are consistent

//copy assignment

value_type & KSArray::operator [] (typename KSArray<AType>::size_type index)
 {
 	value_type holder;
 	return (&holder);
 }

 const value_type & KSArray::operator [] (typename KSArray<AType>::size_type index) const
 {
 	const value_type holder;
 	return (&holder);
 }




#endif