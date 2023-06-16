/*
    Time Complexity : O(N *maxDeadline)
    Space Complexity :O(maxDeadline)

    Where 'N' is size of the array "jobs" and 
    'maxDeadline' is the maximum among all the deadlines.
*/

#include <algorithm>

// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a slots array of size maxDeadline + 1.
    bool slots[maxDeadline + 1];

    // Initialize the array to false initially.
    for (int i = 0; i <= maxDeadline; i++)
    {
        slots[i] = false;
    }

    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {

            if (slots[j] == false)
            {
                maxProfit = maxProfit + jobs[i][1];
                slots[j] = true;
                break;
            }
        }
    }

    return maxProfit;
}
