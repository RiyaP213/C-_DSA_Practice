#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Returns true if all brackets are balanced
bool isValid(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {

        char ch = str[i];

        // If opening bracket, push into stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }

        // Otherwise it is a closing bracket
        else {

            // No opening bracket available
            if (s.empty()) {
                return false;
            }

            // Check whether top opening bracket matches current closing bracket
            char top = s.top();

            if ((top == '(' && ch == ')') ||
                (top == '[' && ch == ']') ||
                (top == '{' && ch == '}')) {

                // Correct pair found
                s.pop();
            }
            else {
                // Wrong pair
                return false;
            }
        }
    }

    // If stack is empty, every opening bracket found its closing bracket
    return s.empty();
}

int main() {

    string str1 = "([)]";      // Invalid
    string str2 = "([{}])";    // Valid
    string str3 = "()[]{}";    // Valid
    string str4 = "(((";       // Invalid

    cout << isValid(str1) << endl;   // 0
    cout << isValid(str2) << endl;   // 1
    cout << isValid(str3) << endl;   // 1
    cout << isValid(str4) << endl;   // 0

    return 0;
}



/* We scan the string from left to right.

If we see an opening bracket:
    Push it into the stack.

If we see a closing bracket:
    1. If stack is empty → invalid.
    2. Otherwise compare with stack top.
       If matching pair:
            pop.
       Else:
            invalid.

After scanning the whole string:

If stack is empty:
    Every opening bracket found a matching closing bracket.
    → Valid

Else:
    Some opening brackets never got closed.
    → Invalid*/