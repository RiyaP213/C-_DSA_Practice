#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int rows = 5;
    int cols = 5;
    int key = 9;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == key) {
                cout << "Found at row: " << i << ", col: " << j;
                return 0;
            }
        }
    }

    cout << "Not found";
    return 0;
}