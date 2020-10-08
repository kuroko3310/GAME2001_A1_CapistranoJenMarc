#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main()
{	
	cout << "Which type of array do you want to test (type 0 for OrderedArray or type 1 for UnorderedArray):" <<endl;
	int type;
	cin >> type;
	if (type != 0 && type !=1)
	{
		while (type != 0 && type !=1)
		{
			cout << "Please input 0 or 1\n";
			cin >> type;
		}
	}
	cout << "Enter the size of array you want: " << endl;
	int size;
	cin >> size;
	if (size < 0 ) 
	{
		while (size < 0)
		{
			cout << "Please input a reasonable value\n";
			cin >> size;
		}
	}
	if (type == 0)
	{
		OrderedArray<int> arr(size);
		cout << "TEST if Ordered Array accepts Duplicate Data" << endl;
		// Enter the elements of the array
		cout << "Enter the elements of the array: " << endl;
		while (arr.GetSize() != arr.GetMaxSize()) {
			int x;
			cin >> x;
			arr.push(x);
		}


		cout << "size is: " << arr.GetSize() << endl;
		cout << "Max size is: " << arr.GetMaxSize() << endl;
		

		// Displaying the elements
		cout << "Here are the elements of the array: " << endl;
		for (int i = 0; i < arr.GetSize(); i++)
		{
			cout << " " << arr[i] << endl;
		}
		

		// Testing the expand function
		cout << "\n";
		cout << "TEST the expand" << endl;
		arr.SetGrowSize();
		cout << "Add one element to the array: " << endl;
		int x;
		cin >> x;
		for (int j = 0; j < arr.GetSize(); j++)
		{
			arr.search(x);
			while (x == arr[j])
			{
				cout << x << " is a copy\n";
				cout << "input another data: ";
				cin >> x;
			}

		}
		arr.push(x);

		// Displaying the elements
		cout << "Here are the elements of the array after adding an element: " << endl;
		for (int i = 0; i < arr.GetSize(); i++)
		{
			cout << " " << arr[i] << endl;
		}

		cout << "After expanding, size is: " << arr.GetSize() << endl;
		cout << "Max size is: " << arr.GetMaxSize() << endl;
		cout << "Grow size is : " << arr.GetGrowSize() << endl;

		// Testing the search
		cout << "\n";
		cout << "TEST the search" << endl;
		cout << "which element do you want to search: " << endl;
		int z;
		cin >> z;
		if (arr.search(z) > 0)
			cout << "Index for " << z << " is: " << arr.search(z) << endl;
		else
			cout << "Did not find the value you were looking for.\n";

		return 0;
	}
	if (type == 1)
	{
		UnorderedArray<int> arr(size);
		// Enter the elements
		cout << "Enter the elements of the array: " << endl;
		while (arr.GetSize() != arr.GetMaxSize()) {
			int x;
			cin >> x;
			arr.push(x);
		}

		cout << "size is: " << arr.GetSize() << endl;
		cout << "Max size is: " << arr.GetMaxSize() << endl;
		

		// Displaying the elements
		cout << "Here are the elements of the array: " << endl;
		for (int i = 0; i < arr.GetSize(); i++)
		{
			cout << " " << arr[i] << endl;
		}

		// Testing the expand
		cout << "\n";
		cout << "TEST the expand" << endl;
		arr.SetGrowSize();
		cout << "Add one element to the array: " << endl;
		int x;
		cin >> x;
		arr.push(x);

		// Displaying the elements
		cout << "Here are the elements of the array after adding an element: " << endl;
		for (int i = 0; i < arr.GetSize(); i++)
		{
			cout << " " << arr[i] << endl;
		}

		cout << "After expanding, size is: " << arr.GetSize() << endl;
		cout << "Max size is: " << arr.GetMaxSize() << endl;
		cout << "Grow size is : " << arr.GetGrowSize() << endl;

		// Testing the search
		cout << "\n";
		cout << "TEST the search" << endl;
		cout << "which element do you want to search: " << endl;
		int z;
		cin >> z;
		if (arr.search(z) > 0)
			cout << "Index for " << z << " is: " << arr.search(z) << endl;
		else
			cout << "Did not find the value you were looking for.\n";

		return 0;
		
	}
}


