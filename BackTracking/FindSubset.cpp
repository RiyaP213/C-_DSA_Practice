#include<iostream>
#include<string>
#include<vector>
using namespace std;

// find and print all subsets of a given set using backtracking
void PrintSubset(string str, string subset){
    if (str.size()==0){
        cout<<subset<<endl;
        return;
    }
    char ch = str[0];
    // exclude the first character

    PrintSubset(str.substr(1), subset + ch);// include the first character
    PrintSubset(str.substr(1), subset);// exclude the first character
}


int main(){
    string str = "abc";
    string subset = "";
    return 0;
}
