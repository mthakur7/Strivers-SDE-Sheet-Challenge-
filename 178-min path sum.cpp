/*
    Time Complexity: O(N * M)
    Space Complexity: O(1)

    Where 'N' is the number of rows and 'M' is the number of columns in grid.
*/

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Iterating all the grid cells.
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {   
            // If it is the bottom rightmost cell.
            if (i == n - 1 && j == m - 1) {
                continue;
            }
            // If the cell is in last row.
            else if (i == n - 1) {
                grid[i][j] = grid[i][j] + grid[i][j + 1];
            }
            // If the cell is in last column.
            else if (j == m - 1) {
                grid[i][j] = grid[i][j] + grid[i + 1][j];
            }
            // Else store the value which will be minimum of both the directions.
            else {
                grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
    }
    // Return the minimum path sum.
    return grid[0][0];
}

