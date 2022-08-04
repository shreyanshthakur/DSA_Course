
bool isSafe (vector<vector<int>>& sudoku, int row, int col, int k) {
    int n = sudoku[0].size();
    for (int i = 0; i < n; i++) {
        
        if (sudoku[row][i] == k)
            return false;
        if (sudoku[i][col] == k) 
            return false;
        int starRow = 3*(row/3) + i/3;
        int starCol = 3*(col/3) + i%3;
        if (sudoku[starRow][starCol] == k)
            return false;
    }
    return true;
}

bool solve (vector<vector<int>>& sudoku) {
    int n = sudoku[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //find Empty space
            if (sudoku[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {                    
                    if (isSafe(sudoku, i, j, k)) {
                        //fill the space
                        sudoku[i][j] = k;  
                        
                        //recursive call to check further solution possible
                        bool fsp = solve (sudoku);
                        if (fsp) {
                            return true;
                        }
                        else {
                            //backtrack - remove value from block
                            sudoku[i][j] = 0;
                        }
                    }
                }
                //if none in 1 to 9 returned true 
                return false;
            }
        }
    }
    //no false came after all blocks are traversed
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    solve (sudoku);
}