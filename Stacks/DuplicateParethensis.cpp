#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Returns true if duplicate parentheses exist
bool isDuplicate(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // Push everything except closing bracket
        if (ch != ')') {
            s.push(ch);
        }
        else {
            /*
            We found ')'.

            If stack top is already '(',
            then nothing exists between them:

            ()

            Therefore, duplicate parentheses exist.
            */
            if (!s.empty() && s.top() == '(') {
                return true;
            }

            /*
            Remove everything inside the current pair
            until we reach '('.
            */
            while (!s.empty() && s.top() != '(') {
                s.pop();
            }

            // Remove the matching '('
            if (!s.empty()) {
                s.pop();
            }
        }
    }

    return false;
}

int main() {
    string str1 = "((a+b))";       // duplicate: true
    string str2 = "((a+b)+(c+d))"; // duplicate: false
    string str3 = "(a+b)";         // duplicate: false
    string str4 = "((a))";         // duplicate: true

    cout << isDuplicate(str1) << endl; // 1
    cout << isDuplicate(str2) << endl; // 0
    cout << isDuplicate(str3) << endl; // 0
    cout << isDuplicate(str4) << endl; // 1

    return 0;
}