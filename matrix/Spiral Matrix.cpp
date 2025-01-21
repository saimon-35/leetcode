#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty()) return ans;
    
    int a = 0, b = matrix.size() - 1;
    int c = 0, d = matrix[0].size() - 1;
    
    while (a <= b && c <= d) {// a, b, c, d are the boundaries of the matrix
        for (int j = c; j <= d; j++) ans.push_back(matrix[a][j]); // Right
        a++;
        for (int i = a; i <= b; i++) ans.push_back(matrix[i][d]); // Down
        d--;
        if (a <= b) {// Check if the row still exists
            for (int j = d; j >= c; j--) ans.push_back(matrix[b][j]); // Left
            b--;
        }
        if (c <= d) {// Check if the column still exists
            for (int i = b; i >= a; i--) ans.push_back(matrix[i][c]); // Up
            c++;
        }
    }
    
    return ans;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}};
    vector<int> result = spiralOrder(matrix);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
