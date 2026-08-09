#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job Sequencing Problem
//
// Goal:
// Select jobs to maximize total profit.
//
// Assumption:
// Every job takes exactly 1 unit of time.
//
// Greedy approach:
//
// 1. Store each job as an object:
//    (index, deadline, profit)
//
// 2. Sort jobs by profit in decreasing order.
//
// 3. For each job, try to schedule it in the
//    latest available slot before its deadline.
//
// Why latest?
// Because this keeps earlier slots available
// for jobs with smaller deadlines.

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> jobData) {

    int n = jobData.size();

    vector<Job> jobs;

    // pair.first  = deadline
    // pair.second = profit

    for (int i = 0; i < n; i++) {

        jobs.push_back(
            Job(i, jobData[i].first, jobData[i].second)
        );
    }

    // Sort by profit in decreasing order
    sort(
        jobs.begin(),
        jobs.end(),
        [](Job& a, Job& b) {
            return a.profit > b.profit;
        }
    );

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // slot[t] tells us whether time slot t is occupied
    //
    // We ignore index 0 and use:
    // 1, 2, 3 ... maxDeadline
    vector<bool> slot(maxDeadline + 1, false);

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        // Start from this job's deadline
        // and move backwards looking for a free slot
        for (int t = jobs[i].deadline; t > 0; t--) {

            if (!slot[t]) {

                // Schedule job here
                slot[t] = true;

                totalProfit += jobs[i].profit;

                cout << "Selecting Job "
                     << jobs[i].idx
                     << " at slot "
                     << t
                     << endl;

                break;
            }
        }
    }

    cout << "Maximum profit = "
         << totalProfit
         << endl;

    return totalProfit;
}

int main() {

    // pair = {deadline, profit}

    vector<pair<int, int>> jobs = {
        {4, 20},
        {1, 10},
        {1, 40},
        {1, 30}
    };

    maxProfit(jobs);

    return 0;
}