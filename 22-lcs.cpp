/*  
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the length of the given array.
*/

#include <unordered_set>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // To store length of longest consecutive sequence.
    int mx = 0;

    // To store the length of current consecutive Sequence.
    int count = 0;

    // To store all the unique elements of array.
    unordered_set<int> set;

    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int previousConsecutiveElement = arr[i] - 1;

        if (set.find(previousConsecutiveElement) == set.end()) {

            // 'arr[i]' is the first value of consecutive sequence.
            int j = arr[i];
            
            while (set.find(j) != set.end()) {
                // The next consecutive element by will be j + 1.
                j++;
            }

            // Update maximum length of consecutive sequence.
            mx = max(mx, j - arr[i]);
        }

    }

    return mx;
}
