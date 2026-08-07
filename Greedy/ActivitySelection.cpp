#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {

    // We assume activities are already sorted
    // according to their end times.

    // Select A0 first because it ends earliest.
    cout << "Selecting A0\n";

    int count = 1;

    // Ending time of last selected activity
    int currentEndTime = end[0];

    for (int i = 1; i < start.size(); i++) {

        // If current activity starts after or exactly
        // when the previous selected activity ends,
        // then it does not overlap.
        if (start[i] >= currentEndTime) {

            cout << "Selecting A" << i << "\n";

            count++;

            // Update ending time
            currentEndTime = end[i];
        }
    }

    return count;
}

int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << "Maximum activities = "
         << maxActivities(start, end)
         << "\n";

    return 0;
}