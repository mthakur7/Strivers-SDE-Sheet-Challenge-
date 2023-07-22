/* 
    Time Complexity : O(N ^ 2)
    Space Complexity : O(1)

    Where 'N' is the total number of elements in the array/list.
*/

long long getInversions(long long *arr, int n){
    // Variable to store the total inversions in the array.
    long long totalInversions = 0;

    // Check for each element whether any smaller element is present on right side.
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                ++totalInversions;
            }
        }
    }
    return totalInversions;
}
