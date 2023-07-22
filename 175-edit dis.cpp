/*
    Time Complexity : O(N * M)
    Space Complexity : O(N * M)
    Where N is the size of first string and M is the size of second string
*/

int editDistance(string str1, string str2)
{
	int n = str1.size(), m = str2.size();
	int **dp = new int *[n + 1];

	// dp[i][j] stores the edit distance of the i+1th length substring of str1 and
	// j+1th length substring of str2 starting from 0 index

	// dynamically allocate memory of size N for each row
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[m + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			// If first string is empty, only option is to
			// insert all characters of second string considering other string of j length
			// so min operation would be j
			if (i == 0)
			{
				dp[i][j] = j;
			}

			else if (j == 0)
			{
				dp[i][j] = i;
			}

			// If last characters are same, then it doesnt cost anything
			else if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}

			// If the last character is different, consider all
			// possibilities and find the minimum
			else
			{
				dp[i][j] = 1 + min(min(dp[i][j - 1],
									   dp[i - 1][j]),
								   dp[i - 1][j - 1]);
			}
		}
	}
	int ans = dp[n][m];

	//Clearing the dynamic array
	for (int i = 0; i <= n; i++)
	{
		delete[] dp[i];
	}

	delete[] dp;
	return ans;
}
