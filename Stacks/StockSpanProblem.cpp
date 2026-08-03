#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Stock span:
// Maximum number of consecutive days, including today,
// for which the stock price was less than or equal to today's price.
void stockSpan(const vector<int>& stocks, vector<int>& span) {
    stack<int> s; // stores indices

    // First day always has span 1
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stocks.size(); i++) {
        int currentPrice = stocks[i];

        /*
        Remove all previous days whose price is
        less than or equal to today's price.

        They cannot limit today's span.
        */
        while (!s.empty() &&
               currentPrice >= stocks[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            /*
            No greater price exists on the left.

            Therefore, the span includes all days
            from index 0 to index i.
            */
            span[i] = i + 1;
        }
        else {
            /*
            s.top() is the nearest previous day
            with a price greater than today's price.
            */
            int previousHigh = s.top();
            span[i] = i - previousHigh;
        }

        // Current index may be useful for future days
        s.push(i);
    }
}

int main() {
    vector<int> stocks = {
        100, 80, 60, 70, 60, 85, 100
    };

    vector<int> span(stocks.size(), 0);

    stockSpan(stocks, span);

    cout << "Stock spans:\n";

    for (int value : span) {
        cout << value << " ";
    }

    cout << "\n";

    return 0;
}