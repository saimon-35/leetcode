#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> vis(10, false); // Correct initialization
        
        // Check rows
        for(int i = 0; i < 9; i++){
            fill(vis.begin(), vis.end(), false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int t = board[i][j] - '0';
                if(vis[t]) return false;
                vis[t] = true;
            }
        }
        
        // Check columns
        for(int i = 0; i < 9; i++){
            fill(vis.begin(), vis.end(), false);
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                int t = board[j][i] - '0';
                if(vis[t]) return false;
                vis[t] = true;
            }
        }
        
        // Check 3x3 subgrids
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                fill(vis.begin(), vis.end(), false);
                for(int k = i; k < i + 3; k++){
                    for(int l = j; l < j + 3; l++){
                        if(board[k][l] == '.') continue;
                        int t = board[k][l] - '0';
                        if(vis[t]) return false;
                        vis[t] = true;
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    bool result = sol.isValidSudoku(board);
    cout << (result ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    return 0;
}