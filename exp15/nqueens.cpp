
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        // Check same column
        if (board[i] == col)
            return false;

        // Check diagonals
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQueens(vector<int>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;

            if (solveNQueens(board, row + 1, n))
                return true;

            // Backtrack
            board[row] = -1;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive value of N.\n";
        return 0;
    }

    vector<int> board(n, -1);

    if (solveNQueens(board, 0, n)) {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists for N = " << n << '\n';
    }

    return 0;
}

