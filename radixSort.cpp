// Radix Sort: Internally Uses Counting Sort
// Time Complexity : O(d*(n+b))
// d - O(logn to base b) (No. of times countSort gets called)
// b - base (decimal), n - length of array
// Used when wide range of elements
// Sorting done from LSB to MSB


#include <stdio.h>
#include <cstring>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    
    for(int i = 1;i < n; i++){
        if(arr[i]>mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n];
    
    int count[10];
    
    memset(count,0, sizeof(count));
    int b = 10;
    for(int i = 0; i < n; i++)
        count[(arr[i]/exp)%b] += 1;
        
    for(int i = 1; i < b; i++)
        count[i] += count[i-1];
    
    for(int i = n-1;i >= 0; --i){
        output[count[(arr[i]/exp)%b]-1] = arr[i];
        count[(arr[i]/exp)%b]--;
    }
    
    for(int i = 0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int m = getMax(arr,n);
    
    for(int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr,n,exp);
}
void printArray(int arr[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
}
int main(){
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = 8;
    radixSort(arr,n);
    printArray(arr,n);
    return 0;
}