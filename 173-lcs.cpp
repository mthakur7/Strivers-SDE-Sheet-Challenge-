/*
    Time Complexity : O(N * M)
    Space Complexity : O(N * M)
    where N and M are the lengths of str1 and str2 respectively.
*/

int lcsHelper(string str1, int n, string str2, int m, int **dp)
{
    // If the length of first string is zero, we don't have any common subsequence
    if (m == 0)
    {
        return 0;
    }

    // If the length of second string is zero, we don't have any common subsequence
    if (n == 0)
    {
        return 0;
    }

    // If already computed the answer for this state, we simply return it.
    if (dp[n - 1][m - 1] != -1)
    {
        return dp[n - 1][m - 1];
    }

    if (str1[n - 1] != str2[m - 1])
    {
        /*
            If the mth character of str1 is not equal to the nth character of str2,
            we return the maximum of answers obtained by
            1. Ignoring the nth character in the first string
            2. Ignoring the mth character in the second string
        */

        dp[n - 1][m - 1] = max(lcsHelper(str1, n - 1, str2, m, dp),
                               lcsHelper(str1, n, str2, m - 1, dp));
    }
    else
    {
        /*
            If the nth character of str1 is equal to the mth character of str2,
            this character will be included in the subsequence.
            Hence, we will add 1 to the length of lcs obtained
            removing the mth character from the first string and the
            nth character from the second string.
        */

        dp[n - 1][m - 1] = 1 + lcsHelper(str1, n - 1, str2, m - 1, dp);
    }

    return dp[n - 1][m - 1];
}

int lcs(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    int **dp = new int *[n];

    // Fill the dp Array with -1 which signifies none of the states have been computed.
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[m];

        for (int j = 0; j < m; ++j)
        {
            dp[i][j] = -1;
        }
    }

    int ans = lcsHelper(str1, n, str2, m, dp);

    for(int i = 0; i < n; ++i)
    {
        delete[] dp[i];
    }

    delete[] dp;

    return ans;
}
