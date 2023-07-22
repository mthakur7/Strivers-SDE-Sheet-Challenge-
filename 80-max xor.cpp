/*
    Time Complexity: O(N * log (M))
    Space Complexity: O(N)

    Where ‘N’ is the length of the given array and 'M' the maximum value in the array.
*/

#include <unordered_set>
int maximumXor(vector<int> A)
{   
    int ans = 0;
    
    int mask = 0;
    int n = A.size();
    unordered_set<int> s;

    for (int i = 30; i >= 0; i--)
    {   
        

        // Setting the ith bit 1 in mask.
        mask = mask | (1 << i);

        for (int j = 0; j < n; j++)
        {   
            // Inserting prefix bitmask into the set.
            s.insert(A[j] & mask);
        }

        int tempAns = ans;

        // Setting the ith bit 1.
        tempAns = tempAns | (1 << i);

        for(auto it: s)
        {   
            // Checking if 'it' xor 'tempAns' is present in set. 
            if(s.count(it ^ tempAns))
            {   
                ans = tempAns;
                break;
            }
        }

        s.clear();
    } 

    return ans;
}
