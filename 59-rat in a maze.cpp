/*
    Time complexity : O(4 ^ (N ^ 2))
    Space complexity : O(N ^ 2)

    Where 'N' is the dimension of the matrix.
*/

void insertCurrentState(vector<vector<int>> &solution, vector<vector<int>> &ans, int n){
    // Insert the solution matrix element by element in ans.
    vector<int> currentState;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            currentState.push_back(solution[i][j]);
        }
    }
    ans.push_back(currentState);
}

void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &ans, int x, int y, int n){
    // Base case that we reach our destination.
    if (x == n - 1 && y == n - 1){
        solution[x][y] = 1;
        // Call to add the updated solution matrix in 'ANS'.
        insertCurrentState(solution, ans, n); 
        return;
    }

    // Condition of out of boundary of the maze.
    if (x > n - 1 || x < 0 || y > n - 1 || y < 0){
        return;
    }

    /*
       Condition for 'MAZE[x][y]==0' - if that particular cell is block.
       'SOLUTION[x][y]'' == 1 - if it is already visited or already we go through it.
    */
    if (maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }

    // No problem comes in visiting this cell so visit it.
    solution[x][y] = 1;

    // Recursive calls to all directions(call to function having same name with diff value of params).
    // Up move.
    solveMaze(maze, solution, ans, x - 1, y, n); 
    // Down move.
    solveMaze(maze, solution, ans, x + 1, y, n); 
    // Left move.
    solveMaze(maze, solution, ans, x, y - 1, n); 
    // Right move.
    solveMaze(maze, solution, ans, x, y + 1, n);

    // Backtracking if there is no further path exists.
    solution[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> maze, int n){
    // Initialize the 'SOLUTION' matrix by all 0s.
    vector<vector<int>> solution(n, vector<int>(n, 0));

    // Vector used to store all the paths.
    vector<vector<int>> ans;

    // Final call to function to print the solutions.
    solveMaze(maze, solution, ans, 0, 0, n);

    // Return the updated ans.
    return ans;
}
