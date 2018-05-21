#include <iostream>
using namespace std;

void swap2(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b=temp;
}
void printArray2(int a[],int len){
	cout<<"Sorted Array is : "<<endl;
	for(int j=0;j<len;j++)
		cout<<a[j]<<",";
	cout<<endl;
}
void ShellSort(int arr[],int len){
	for(int gap = len/2;gap>0; gap /= 2){
		for(int j= gap;j<len;j++){
			int temp = arr[j];
			int i;
			for(i=j; i>=gap && arr[i-gap]>temp; i-=gap){
				arr[i] = arr[i-gap];
				printArray2(arr,len);
			}
			arr[i] =temp;
			cout<<"Hello";
			printArray2(arr,len);

		}
	}
}

int main(){
	int arr[] ={5,4,6,2,1};
	int len = (sizeof(arr)/sizeof(arr[0]));
	ShellSort(arr,len);
	printArray2(arr,len);
	return 0;
}
