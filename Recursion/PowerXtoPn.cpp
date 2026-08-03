#include<iostream>
using namespace std;

long long powerLoop(int x, int n) {// using loop-time complexity: 0(n)
    long long answer = 1;

    for (int i = 0; i < n; i++) {
        answer *= x;
    }

    return answer;
}

//using recudrsion-time complexity: 0(n)


long long powerRecursive(int x, int n) {
    if (n == 0) {
        return 1;
    }

    return x * powerRecursive(x, n - 1);
}

//fast exponentiation-time complexity: 0(log n)
long long powerFast(long long x, int n) {
    long long answer = 1;

    while (n > 0) {
        // If the current binary bit of n is 1,
        // include the current value of x.
        if (n & 1) {
            answer *= x;
        }

        // Prepare the next power:
        // x, x², x⁴, x⁸, ...
        x *= x;

        // Remove the last binary bit of n.
        n >>= 1;
    }

    return answer;
}

int main() {
    cout << powerLoop(2, 5) << endl;
    cout << powerRecursive(2, 5) << endl;
    cout << powerFast(2, 5) << endl;
    
    return 0;
}

