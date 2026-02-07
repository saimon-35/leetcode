// LeetCode : Shuffle the Array
// Problem link : https://leetcode.com/problems/shuffle-the-array/description/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0, j = n; i < n; i++, j++){
            nums[i] = nums[i] << 10;
            nums[i] = nums[i] | nums[j];
        }
        for(int i = n - 1, j = 2 * n - 1; i >= 0; j -= 2, i--){
            int p = nums[i];
            int mask1 = (1 << 10) - 1;
            int q = p & mask1;
            int mask2 = ((1 << 10) - 1) << 10;
            int r = (p & mask2) >> 10;
            nums[j] = q;
            nums[j - 1] = r; 
        }
        return nums;
    }
};
