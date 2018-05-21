#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a=*b;
	*b =temp;
}
int partition(int arr[], int lo, int hi){
	int i =lo-1;
	int pivot = arr[hi];
	for (int j=lo;j<=hi-1;j++){
		if(arr[j] <= pivot){
			i = i+1;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[hi]);
	return i+1;
}
void QuickSort(int a[],int lo, int hi){
	if(lo<hi){
		int p = partition(a,lo,hi);
		QuickSort(a,lo,p-1);
		QuickSort(a,p+1,hi);
	}
}

void printArray(int a[],int len){
	cout<<"Sorted Array is : "<<endl;
	for(int j=0;j<len;j++)
		cout<<a[j]<<",";
}
int main2(){

	int arr[] ={5,4,2,8,6,3,9,10,15};
	int len = (sizeof(arr)/sizeof(arr[0]));
	QuickSort(arr,0,len-1);
	printArray(arr,len);
	return 0;

}
