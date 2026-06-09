#include<iostream>
using namespace std;

/* This program lets the user specify the size of an array, then takes input for the elements of the aray,
finds that largest element in the array and prints it to the user. */

int Largest(int arr[], int size){

    int largest = INT_MIN;
    for (int i=0; i<size; i++){
        if (arr[i]>largest){
            largest=arr[i];
    
        }
    return largest;

}}

int main()
{ int size;
  cout << "Enter the size of the array: ";
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " elements: ";
  for (int i=0;i<size;i++){
    cin >> arr[i];
  }
  cout << "The largest element in the array is: " << Largest(arr,size) << endl;
  return 0;
}