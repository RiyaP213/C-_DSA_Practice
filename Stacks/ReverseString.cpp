#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    string ans;
    stack<char> s;

    // Push every character into the stack
    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    // Pop characters in reverse order
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string str = "abcd";

    cout << reverseString(str) << endl;

    return 0;
}