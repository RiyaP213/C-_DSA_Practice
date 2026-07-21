#include<iostream>
using namespace std;

// uses less space
//Quick sort apporach is b ased on the divide and conquer algorithm.
// It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, 
//according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

/* Speudocode:
function quicksort(arr, low, high)
    if low < high then
        pivot_index = partition(arr, low, high)
        quicksort(arr, low, pivot_index - 1)
        quicksort(arr, pivot_index + 1, high)*/
int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];// last element as pivot
    for (int j=si; j<ei; j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}
void QuickSort(int arr[],int si, int ei){
    if(si>=ei){
        return;
    }

   int pivotIdx = partition(arr, si, ei);
   QuickSort(arr, si, pivotIdx - 1);// left half
   QuickSort(arr, pivotIdx + 1, ei);//  right half

}
void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 int main(){

int arr[6]={6,3,7,5,2,4};
int n =6;
QuickSort(arr, 0, n-1);
printArray(arr, n);
return 0;
}
