/*
    Time Complexity:  O((2^N) * N).
    Space Complexity:O( 1 ).

    Where 'N' is the size of the array.
*/

vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{
    // Ans vector contains all the subset which sum upto 'K'.
    vector<vector<int>> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            // Checking wheather the element is present the subset or not.
            if ((1 << j) & i)
            {
                sum += arr[j];
                vec.push_back(arr[j]);
            }
        }

        // If sum is 'K'.
        if (sum == k)
        {
            ans.push_back(vec);
        }
    }

    // Return ans.
    return ans;
}
