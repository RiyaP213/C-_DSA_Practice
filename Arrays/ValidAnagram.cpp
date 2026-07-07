#include<iostream>
#include<string>
using namespace std;
bool isAnagram(string str1, string str2){

    
    if(str1.length()!=str2.length()){
        return false;
    }
    int count[26]={0};
    for(int i=0;i<str1.length();i++){
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            return false; 
        }
        }

            return true;

        }

int main(){
    string str1="listen";
    string str2="silent";
    if(isAnagram(str1,str2)){
        cout<<"Anagram";

    }
    else{
        cout<<"Not Anagram";
    }

    return 0;
}