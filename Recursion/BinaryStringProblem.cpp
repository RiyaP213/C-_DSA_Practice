#include <iostream>
#include <string>
using namespace std;

// Print all binary strings of length n
// without consecutive 1s
void binaryStrings(int n, string ans, int lastDigit) {
    // Base case: required length is complete
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    // Adding 0 is always allowed
    binaryStrings(n - 1, ans + '0', 0);

    // Add 1 only when the previous digit was not 1
    if (lastDigit == 0) {
        binaryStrings(n - 1, ans + '1', 1);
    }
}

int main() {
    int n = 3;

    binaryStrings(n, "", 0);

    return 0;
}