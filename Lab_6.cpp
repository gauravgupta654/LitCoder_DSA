#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board, int n) {
    for (int i = 0; i < n; i++) {
        set<char> row;
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                if (row.count(board[i][j])) return false;
                row.insert(board[i][j]);
            }
        }
    }
    
    for (int j = 0; j < n; j++) {
        set<char> col;
        for (int i = 0; i < n; i++) {
            if (board[i][j] != '.') {
                if (col.count(board[i][j])) return false;
                col.insert(board[i][j]);
            }
        }
    }
    
    for (int boxRow = 0; boxRow < n; boxRow += 2) {
        for (int boxCol = 0; boxCol < n; boxCol += 2) {
            set<char> box;
            for (int i = boxRow; i < boxRow + 2; i++) {
                for (int j = boxCol; j < boxCol + 2; j++) {
                    if (board[i][j] != '.') {
                        if (box.count(board[i][j])) return false;
                        box.insert(board[i][j]);
                    }
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    if (isValidSudoku(board, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
