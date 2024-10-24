#ifndef SEARCHNLIST_H
#define SEARCHNLIST_H
#include "Collection.h"
#include <iostream>
using namespace std;
namespace seneca {
	// T1 -> Car, Employees
	// T2: int, char, double
	// Requirements for T1:
	//   - Must have a copy constructor.
	//   - Must have a copy assignment operator.
	//   - Must have the "==" operator defined to compare objects.
	// Requirements for T2:
	//   - Must be a type that can be compared using the "==" operator.
	template <typename T1 , typename T2>
	bool search(Collection <T1>& tempObj, T1 array[], int arraySize, T2 key) {
		int j = 0;
		for (int i = 0; i < arraySize; i++) {
			
			if (array[i] == key) {
				
				tempObj.resize(j);
				tempObj.add(array[i]);
			
				j++;
			}
	
		}

		return j;
	}
	
	// Requirements for T:
   //   - Must have the "<<" operator defined to be stream insertable.
	template <typename T>
	void listArrayElements (const char* title, const T array[], int size) {
		cout << title << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ": " << array[i]<<endl;
		}
	}

}

#endif



