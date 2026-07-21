#include<iostream>
#include<string>

using namespace std;


void permutations(string str, string ans){
    int n = str.size();
    if (str.size()==0){
        cout<<ans<<endl;
        return;
    }
    for (int i=0;i<str.size();i++){
        char ch = str[i];
        string nextstr = str.substr(0,i)+ str.substr(n-i-1);
        permutations(nextstr, ans + ch);
    }
}

int main(){
    string str = "abc";
    string ans = "";
    permutations(str, ans);
    return 0;

}

// total permutations of a string of length n is n! (n factorial). 
//For example, for a string of length 3, there are 3! = 6 permutations: "abc", "acb", "bac", "bca", "cab", "cba".
// time complexity: O(n*n!) because for each of the n! permutations, we are creating a new string of length n.
