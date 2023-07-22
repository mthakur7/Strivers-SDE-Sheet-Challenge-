/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(N)

    Where N is the number of Dumbbells in RACK
*/


int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int dp[n];
    int totalWeight = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        dp[i] = rack[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            // Choose element which is smaller than last element.
            if(rack[i] > rack[j] && dp[i] < dp[j] + rack[i])
            {
                dp[i] = dp[j] + rack[i];
            }
        }

        // Store the maximum weigth in 'totalWeight'.
        totalWeight = max(totalWeight, dp[i]);
    }

    return totalWeight;
}
