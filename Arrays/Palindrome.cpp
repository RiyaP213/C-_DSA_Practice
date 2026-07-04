#include<iostream>
using namespace std;

bool IsPalindrome(char arr[],int n){
    int start=0;
    int end=n-1;
    while(start<end){
        if(arr[start]!=arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    char arr[]="madam";
    int n=strlen(arr);
    if(IsPalindrome(arr,n)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }

    
}