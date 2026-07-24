#include <iostream>
using namespace std;

void PrintSudoku(int sudoku[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit) {
    // Vertical check
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][col] == digit) {
            return false;
        }
    }

    // Horizontal check
    for(int j = 0; j < 9; j++) {
        if(sudoku[row][j] == digit) {
            return false;
        }
    }

    // 3x3 grid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(sudoku[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    // Base case: all rows completed
    if(row == 9) {
        PrintSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // Skip cells that already contain a number
    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // Try digits 1 to 9
    for(int digit = 1; digit <= 9; digit++) {
        if(isSafe(sudoku, row, col, digit)) {
            // Choose
            sudoku[row][col] = digit;

            // Explore
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            }

            // Undo / backtrack
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int sudoku[9][9] = {
        {0,0,8,0,0,0,0,0,0},
        {4,9,0,1,5,7,0,0,2},
        {0,0,3,0,0,4,1,9,0},
        {1,8,5,0,6,0,0,2,0},
        {0,0,0,0,2,0,8,6,0},
        {9,6,0,4,0,5,3,0,0},
        {0,3,0,0,7,2,0,0,4},
        {0,4,9,0,3,0,0,5,7},
        {8,2,7,0,0,9,0,1,3}
    };

    if(!sudokuSolver(sudoku, 0, 0)) {
        cout << "No solution exists" << endl;
    }

    return 0;
}


/*
-------------------------------- Sudoku Solver --------------------------------

Idea:
Fill the Sudoku one cell at a time.

1. If current cell is already filled
      -> Move to next cell.

2. If current cell is empty
      -> Try digits 1 to 9.
      -> If digit is safe:
            Place digit.
            Solve remaining Sudoku.
            If it fails, remove digit (Backtrack).

3. If all rows are processed (row == 9)
      -> Sudoku solved.

Backtracking Pattern:

Choose
board[row][col] = digit;

Explore
solve(nextRow, nextCol);

Undo
board[row][col] = 0;

-------------------------------------------------------------------------------
Pseudo Code

solve(row, col)

    if row == 9
        return true

    compute next cell

    if current cell already filled
        return solve(next cell)

    for digit = 1 to 9

        if isSafe()

            place digit

            if solve(next cell)
                return true

            remove digit

    return false

-------------------------------------------------------------------------------
isSafe()

Check:
- Same row
- Same column
- Same 3 x 3 box

If digit exists anywhere
    return false

Else
    return true

-------------------------------------------------------------------------------
Time Complexity

Worst Case:
O(9^(n²))

For a 9×9 Sudoku:
At most 81 cells, each trying up to 9 digits.

Space Complexity:
O(n²)

Recursive stack:
O(81) for a standard Sudoku.

-------------------------------------------------------------------------------
Remember:

Empty Cell
    ↓
Try 1..9
    ↓
Safe?
    ↓
Place
    ↓
Recurse
    ↓
Fail?
    ↓
Remove (Backtrack)
    ↓
Try next digit

-------------------------------------------------------------------------------
*/