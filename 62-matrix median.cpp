/*
    Time Complexity : O(N * log(M) * log(MAX - MIN) )
    Space Complexity : O(1)

    Where ‘N’ is the number of rows,
    and ‘M’ is the number of columns in the given matrix,
    and MAX and MIN are the minimum and maximum element of the matrix, respectively.
*/

// It returns the index of the first element in the range [first, last) which compares grater than val.
int upper_bound(vector<int> const &arr, int first, int last, int val)
{
    // Initialise the "low" and "high" appropriately.
    int low = first, high = last;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > val)
        {
            /*
               If the current element is less than val,
               reduce the search space to left half.
            */
            high = mid;
        }
        else
        {
            /*
               If the current element is greater than or equal to val,
               reduce the search space to right half.
            */
            low = mid + 1;
        }
    }

    return low;
}

int getMedian(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    // Since, 1 <= matrix[i][j] <= 10^5, set the "low" and "high" value accordingly.
    int low = 1, high = 100000;

    // Loop until our search spaces convergers to single element.
    while (low < high)
    {

        int mid = (low + high) / 2;

        // To count number of elements less than or equal to "mid".
        int count = 0;

        // Iterate through each row and increment the "count".
        for (int i = 0; i < n; i++)
        {
            /*
               NOTE:
               upper_bound (ForwardIterator first, ForwardIterator last, const T& val);
               Returns an iterator
               pointing to the first element in the range [first,last)
               which compares greater than val.
            */
            count = count + upper_bound(matrix[i], 0, matrix[i].size(), mid);
        }

        if (count >= (n * m + 1) / 2)
        {
            // The median will lie in the range of [“mid”, “high”].
            high = mid;
        }
        else
        {
            // The median will lie in the range of ["mid" + 1, "high"].
            low = mid + 1;
        }
    }
    return low;
}
