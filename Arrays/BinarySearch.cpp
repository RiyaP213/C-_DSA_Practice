#include<iostream>
using namespace std;
 
// Binary Search works only on sorted arrays. It is a divide and conquer algorithm that repeatedly divides the search interval in half. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
// Time complexity: O(log n) because we are halving the search space in each step.
int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(array)/sizeof(array[0]);
    int key;
    cout<<"Enter the element to search for: ";
    cin>>key;
    int start=0;
    int end=size-1;
    bool found=false;
    while(start<=end){
        int mid=(start+end)/2;
        if(array[mid]==key){
            found=true;
            break;
        }
        else if(array[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(found){
        cout<<"Element found in the array."<<endl;  

}
    else{
        cout<<"Element not found in the array."<<endl;
    }
    return 0;
}

// note: Binary search can be implemented using recursion as well, but the iterative version is often preferred in practice due to lower overhead.
// Also, binary search can be used to find the first or last occurrence of a duplicate element in a sorted array by modifying the conditions slightly.
// For example, to find the first occurrence, you would check if the middle element is equal to the key and if it is the first element or if the previous element is different. If so, you have found the first occurrence. Otherwise, you would continue searching in the left half.
// Similarly, to find the last occurrence, you would check if the middle element is equal to the key and if it is the last element or if the next element is different. If so, you have found the last occurrence. Otherwise, you would continue searching in the right half.
// Binary search can also be used to find the position where an element should be inserted in a sorted array to maintain the sorted order. This is often referred to as "lower bound" or "upper bound" depending on whether you want to find the first position where the element can be inserted (lower bound) or the last position (upper bound).
// In C++, the standard library provides functions like std::lower_bound and std::upper_bound that implement these concepts efficiently.
// Note: Binary search is not suitable for linked lists or unsorted arrays, as it relies on random access to elements. In such cases, linear search would be more appropriate.
// Binary search can also be applied to find the square root of a number by treating the problem as finding the largest integer whose square is less than or equal to the given number. This is a common application of binary search in mathematical problems.
// In summary, binary search is a powerful algorithm for searching in sorted arrays with logarithmic time complexity, but it requires careful implementation and is not suitable for all data structures or unsorted data.
// int mid = start + (end - start) / 2;---> this is better than mid=(start+end)/2 because it prevents potential overflow when start and end are large integers. By calculating the difference (end - start) first, we ensure that we are working with smaller numbers, which reduces the risk of overflow. This is a common best practice when implementing binary search to ensure robustness and correctness in all cases.