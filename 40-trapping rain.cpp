/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where N is the total number of elevations.
*/

#include <climits>

long long getTrappedWater(long long *arr, int n){

    //Reference point.
    long long peak = 0;

    // Result.
    long long ans = 0L;


    if (n == 0) {
        return 0LL;
    }

    long long peakVal = arr[0];

    // Moving left to right.
    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    // Initialising a min value.
    long long maxSoFar = LONG_LONG_MIN;
    long long countSubmerged = 0LL;
    long long submergedArea = 0LL;

    // Traversing over a peak.
    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0LL;
            submergedArea = 0LL;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    // Initialising a min value.
    maxSoFar = LONG_LONG_MIN;
    countSubmerged = 0LL;
    submergedArea = 0LL;

    // Moving right to left.
    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0LL;
            submergedArea = 0LL;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
}
