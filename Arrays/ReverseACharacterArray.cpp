#include<iostream>
using namespace std;
void Reverse(char arr[],int n){
    int start=0;
    int end=n-1;
    while(start<end){
        swap(arr[start],arr[end]);

        start++;
        end--;
    }   }

    int main(){
            char arr[]="Hello";
            int n=strlen(arr);
            Reverse(arr,n);
            cout<<arr;
    }