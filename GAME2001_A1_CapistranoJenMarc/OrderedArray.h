#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray : public Array<T>
{
public:
	// Constructor
	Array<T> :: Array;
	// Destructor
	~OrderedArray() {}
	// Insertion -- Big-O = O(N)
	int push(T val)
	{
		assert(Array<T>::m_array != NULL);

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] > val)
			{
				break;
			}
			// Check if there is duplicate
			if (Array<T>::m_array[i] == val)
			{
				std::cout << "duplicate data is not allowed\n";
				Array<T>::remove(i);
				break;
			}
			
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = Array<T>::m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			Array<T>::m_array[k] = Array<T>::m_array[k - 1];
		}

		// Step 3: Insert val into index
		
		Array<T>::m_array[i] = val;

		
		
		Array<T>::m_numElements++;

		return i;
	}

	// Searching -- Binary Search -- Big O = O(log N)
 int search(T searchKey)
	{
	 
		// Call to the binarysearch recursive function
		// Binary Search: searchkey, initial lowerbound, initial upperbound
		return  binarySearch(searchKey, 0, Array<T>::m_numElements - 1);
	}
private:
	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(Array<T>::m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < Array<T>::m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1; // 2^1 == 1

		// Did we find the searchKey at current?
		if (Array<T>::m_array[current] == searchKey)
		{
			// We have found the searchKey in the array. Return index
			return current;
		}
		// Are we done searching?
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Which half is searchKey in?
		else
		{
			if (Array<T>::m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}	
		return -1;
	}
};
