// Workshop 9
// Name: Soham Thaker
// SID: 011-748-159
// Email: sdthaker1@myseneca.ca
// Date of Completion: 2021/03/29
// The below code is my own code except for professor provided code

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

namespace sdds {

	template<typename T, typename U>
	bool search(Collection<T>& C, const T* arr, int size, const U& key) {
		
		int match = 0;

		for (int i = 0; i < size; i++) {
			if (arr[i] == key) {
				C.add(arr[i]); 
				match++;
			}
		}
		return match;
		/*
		The custom types which use this template function must have == operator
		overload to compare the if the key string is present in the custom type.
		*/
	}

	template<typename T>
	void listArrayElements(const char* title, const T arr[], int size) {
		std::cout << title << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << i + 1 << ": " << arr[i] << std::endl;
		}
		/*
		The custom types which use this template function must have <<
		operator overload to print the data members of those custom types.
		*/
	}
}

#endif