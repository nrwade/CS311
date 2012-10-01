/* Nicole Wade
CS311
KSArray.h
Header file for a 'kind of' smart array
Note: There is no .cpp file
Due: 1 Oct. 2012
*/

#ifndef KSARRAY_H
#define KSARRAY_H

// #include....

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

	typedef AType size_type;
	//the type of the size of the array
	//I don't really understand why we need this... humph

	//default constructor
	KSArray();
	
	//constructor 1-parameter
	KSArray(int numItems);

	//constructor 2-parameter
	KSArray(int numItems, value_type val);

	//copy constructor
	KSArray(const KSArray & obj);

	int size();

	value_type *begin();
	const value_type *begin() const;

	value_type *end();
	const value_type *end() const;

	~KSArray();

private:
	//size_type * _sizePtr; // Not sure if I need a pointer to a size_type, but the instructions say I do
	//not sure why this is private

	value_type * _arrayPtr; // pointer to a value_type
		
};

//global functions AND member function definitions go here

//global functions will need to be templates


//default constructor
KSArray::KSArray():
{
	//USE AN INITIALIZER LIST
	_arrayPtr = new value_type[10]; //I feel like this should be a value type 
}
	// should create a KSArray of size 10
	// all items in the array should be default constructed 
	
	//constructor 1-parameter
KSArray::KSArray(int numItems)
{
	//USE AN INITIALIZER LIST
	_arrayPtr = new value_type[numItems];
}
	// parameter is a non-negative integer giving the number of items in the array
	// all items in the array should be default constructed
	//may not create any new implicit type conversions

	//constructor 2-parameter
KSArray::KSArray(int numItems, value_type val)
{
	_arrayPtr = new [numItems];
	//use our iterators begin and end to loop through and set each item in the array to val
	for(iter=begin(); iter<=end(); iter++)//do I need to put KSArray.begin() and end? <= or < end
	{
		*iter=val; //we dereference the pointer and set it to val
	}
}
	// first parameter is a non-negative integer giving the number of items in the array
	// second parameter is an item of the value type- each item in the array should be set to this value

	//copy constructor
KSArray::KSArray(const KSArray & obj)
{
	//WRITE THIS
	//Use initializer list
}
	// must take a const 
	// must have a loop or generic stl algorithm in the body
	// creates a new object

	// sets an existing object equal to a copy of some other existing object
// check for self-assignment. If this is not self-assignment, deallocate the old array nd then do essentially what the copy ctor does
// return the object assigned. See slide 11 for sample code

int KSArray::size()	//returns the number of items in the array
{
	int count=0;
	for (iter=begin(); iter<=end(); iter++)
	{
		count +=count;
	}
	return(count);
}

// the two functions should be essentially identical except for the const at the end of the first line
// and the return method
// or we may use the const_cast trick to call the const version from the non-const version
value_type * KSArray::begin()
{
	return(_arrayPtr);
}

const value_type * KSArray::begin() const
{
	return(_arrayPtr);
}
	//returns a pointer to a value_type
	//returns the address of item 0 in the array

value_type * KSArray::end()
{
	return(begin() + size()+1);//plus one because we need one past the end
}

const value_type *end() const
{
	return(begin() + size()+1);
}
	// returns an iterator to just past the last array item- can be a pointer
	// add a number to the return value of begin- what number? size()
	// returns the address of the item one-past the end of the array (think iterator)

//destructor
~KSArray()
{
	delete _arrayPtr;
}
	// deallocate all memory- aka delete all pointers!

template <typename theType> // does not need to be the same type we're using for our class as it will be passed to the class
bool operator==(const KSArray<theType>& lhs, const KSArray<theType>& rhs)
{
	bool comp = false;

	

	return(lhs.value_type = rhs.value_type && lhs.size() = rhs.size && comp);
}



// two KSArray with the same value type are equal if they have the same size and their corresponding 
// items are all equal.
// Two KSArrays with differnt value types cannot be compared
// Does this need to be a friend to the class?

bool operator!=()
{

}
//operator !=
// two KSArray with the same value type are equal if they have the same size and their corresponding 
// items are all equal.
// Two KSArrays with differnt value types cannot be compared
// We can probably just use our operator== for this 

template <typename TheType>
bool operator<()
{

}

//So if we just us == and < and those are templates, do these need to be templates?
bool operator<=()
{

}

bool operator>()
{

}

bool operator>=()
{

}
//use < and == for all of these
//must compare element by element
//check that all of the operators are consistent

//copy assignment


// ...operator[]()
//...operator[]() const
// given an integer subscript from 0 to size-1 
// where size is the nuber of items in the array, return a reference to the proper item


//template <typename T>
//bool operator<()
//{}





#endif