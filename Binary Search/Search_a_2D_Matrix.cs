public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        
        for(int i = 0; i < matrix.Length; i++){
            int left = 0;
            int right = matrix[i].Length - 1;
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(matrix[i][mid] == target) return true;
                if(matrix[i][mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return false;
    }
}
