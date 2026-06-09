// we are to search for an element in an arrray and return if its found or not
#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int key){
    for (int i=0; i<size; i++){
        if (arr[i]==key){
            return true;
        }
    }
    return false;
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements: ";
    for (int i=0;i<size;i++){
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search for: ";
    cin >> key;
    if (LinearSearch(arr,size,key)){
        cout << "Element found in the array." << endl;
    }
    else{
        cout << "Element not found in the array." << endl;
    }
    return 0;
}