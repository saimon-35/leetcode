class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
    if (matrix.empty()) return ans;
    
    int a = 0, b = matrix.size() - 1;
    int c = 0, d = matrix[0].size() - 1;
    
    while(a <= b && c <= d){
        for(int i = a; i <= d; i++) ans.push_back(matrix[a][i]); //right
        a++;
        for(int j = a; j <= b; j++) ans.push_back(matrix[j][d]); //down
        d--;
        if(a <= b){
            for(int i = d; i >= c; i--) ans.push_back(matrix[b][i]); //left
            b--;
        }
        if(c <= d){
            for(int j = b; j >= a; j--) ans.push_back(matrix[j][c]);
        }
        c++;
    }
    return ans;
    }

};