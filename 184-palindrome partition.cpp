/*
    Time complexity: O(n^3)
    Space complexity: O(n^2)

    Where 'n' is the length of the string
*/
int palindromePartitioning(string str)

{
    // Get the length of the string
    int n = str.length();

    /* Create two arrays to build the solution
     in bottom up manner
     cuts[i][j] = Minimum number of cuts needed for
     palindrome partitioning of substring str[i..j]
     isPalindrome[i][j] = true if substring str[i..j] is  palindrome, else false */

    // cuts[i][j] is 0 if isPalindrome[i][j] is true
    int cuts[n][n];
    bool isPalindrome[n][n];

    // Every substring of length 1 is a palindrome
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
        cuts[i][i] = 0;
    }

    /* L is substring length. Build the solution in bottom up manner by
   considering all substrings of length starting from 2 to n. */

    for (int L = 2; L <= n; L++) {
        /* For substring of length L, set
       different possible starting indexes */
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;  // Set ending index

            /* If L is 2, then we just need to
         compare two characters. Else
         need to check two corner characters
         and value of isPalindrome[i+1][j-1] */
            if (L == 2) {
                isPalindrome[i][j] = (str[i] == str[j]);
            } else {
                isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i + 1][j - 1];
            }

            // If str[i..j] is palindrome, then cuts[i][j] is 0
            if (isPalindrome[i][j] == true) {
                cuts[i][j] = 0;
            } else {
                /* Make a cut at every possible
           location starting from i to j,
           and get the minimum cost cut. */
                cuts[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    cuts[i][j] = min(cuts[i][j], cuts[i][k] + cuts[k + 1][j] + 1);
                }
            }
        }
    }

    // Return the min cut value for
    // complete string. i.e., str[0..n-1]
    return cuts[0][n - 1];
}
