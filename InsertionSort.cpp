/*
 * InsertionSort.cpp
 *
 *  Created on: 06-Jul-2018
 *      Author: Sahil S
 */

#include <stdio.h>
using namespace std;
// InPlace Sorting
// Basically modifies the array only
// Time Complexity:
// Best Case - O(n): Array already Sorted
// Average/Worst Case - O(n^2) - O( (n-2) * (n-1) ) = O(n^2)
// Useful
// 1) Incremental Sorting viz inserting in a sorted array - adaptive
// 2) when array size small

/**
 * Two pointers:
 * i - running from 1 to n-1
 * j - running from 0 to i-1
 * Both are subsequent
 * Run while till j >=0 and data[j] > key
 * key is my outer element
 */
void insertionSort(int data[], int length){
	for(int i = 1; i< length; i++){
		int key = data[i];

		int j = i-1;
		while(j >=0 && data[j] > key){
			data[j+1] = data[j];
			j = j-1;
		}
		data[j+1] = key;
	}
}

void printArray(int data[], int len){
	for(int i = 0;i < len; i++)
		printf("%d ", data[i]);
}
int main_insertionSort(){
	int arr[] = {4,5,6,2,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,len);
	printArray(arr,len);
	return 0;
}

