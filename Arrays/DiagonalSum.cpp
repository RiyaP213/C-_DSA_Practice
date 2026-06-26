#include <iostream>
using namespace std;

int main() {

    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n = 3;
    int sum = 0;

    for(int i=0;i<n;i++){

        // Primary diagonal
        sum += arr[i][i];

        // Secondary diagonal
        if(i != n-1-i){
            sum += arr[i][n-1-i];
        }
    }

    cout << sum;

    return 0;
}