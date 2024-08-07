#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> &board){
  cout << "Printing board: \n";
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSafeToPlaceQueen(const vector<vector<int>> &board, int i, int j) {
    int r = board.size();
    int c = board[0].size();

    // Check row
    for (int x = 0; x < c; x++) {
        if (board[i][x] == 1) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < r; x++) {
        if (board[x][j] == 1) {
            return false;
        }
    }
    
    // Check upper left diagonal
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == 1) {
            return false;
        }
    }

    // Check lower right diagonal
    for (int x = i, y = j; x < r && y < c; x++, y++) {
        if (board[x][y] == 1) {
            return false;
        }
    }

    
    // Check upper right diagonal
    
    for (int x = i, y = j; x >= 0 && y < c; x--, y++) {
        if (board[x][y] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    
    for (int x = i, y = j; x < r && y >= 0; x++, y--) {
        if (board[x][y] == 1) {
            return false;
        }
    }

    return true;
}

void recursiveQueens(vector<vector<int>> &board, int i, int j, int &count) {
    if (count == 8) {
        printBoard(board);
        return;
    }

    if (j >= 8) {
        recursiveQueens(board, i + 1, 0, count);
        return;
    }

    if (i >= 8) {
        return;
    }

    if (isSafeToPlaceQueen(board, i, j)) {
        board[i][j] = 1;
        count++; // Increment count of placed queens
        recursiveQueens(board, i, j + 1, count);
        // Backtrack
        board[i][j] = 0;
        count--; 
    }

    recursiveQueens(board, i, j + 1, count);

}

void queens(int n, int r, int c, vector<int> &q) {
    vector<vector<int>> board(8, vector<int>(8, 0));

    board[r][c] = 1;
    int count = 1; // Start with queen already placed

    // Start recursion from row 0, column 0
    recursiveQueens(board, 0, 0, count);
}
    

int main (){

  int n;
  cin >> n;
  int r, c;
  // solution
  vector<int> q(n*n);

  for(int i = 0; i < n; ++i){
    cin >> r >> c;
  }

  queens(n, r-1, c-1, q);
  

  return 0;
}
