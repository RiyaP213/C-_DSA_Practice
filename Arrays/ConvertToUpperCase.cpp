#include<iostream>
using namespace std;

void ConvertToUpperCase(char word[], int n){
    for(int i=0;i<n;i++){
    if(word[i]>='a' && word[i]<='z'){
        word[i]=word[i]-32;
    }
 }
}

int main(){
     char word[]="ApPle";
        int n=strlen(word);
 ConvertToUpperCase(word,n);
    cout<<word;

}