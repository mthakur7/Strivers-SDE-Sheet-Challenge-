/*
    Time Complexity - O(N^3)
    Space Complexity - O(N)

    where N is the length of the string.
*/

#include <unordered_map>

bool allUnique(string input, int start, int end)
{
    //For storing every character of string
    unordered_map<char, int> set;

    for (int i = start; i < end; i++)
    {
        char ch = input[i];
        /*
            If a character is already there then we have a found duplicates
            so we need to return false
        */
        if (set.find(ch) != set.end()) 
        {
            return false;
        }
        set[ch] = 1;
    }
    return true;
}

int uniqueSubstrings(string input)
{
    int n = input.length();
    int ans = 0;

    //Check for every possible substring
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            //If substring contains unique characters then update the maximum.
            if (allUnique(input, i, j)) 
            {
                ans = max(ans, j - i);
            }
        }
    }
    
    return ans;
}
