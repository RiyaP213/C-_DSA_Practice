#include <iostream>
using namespace std;

int count7s(int mat[][4], int rows, int cols) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 7) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int mat[3][4] = {
        {1, 7, 3, 4},
        {7, 5, 7, 8},
        {9, 10, 11, 7}
    };

    cout << "Number of 7s = " << count7s(mat, 3, 4);

    return 0;
}