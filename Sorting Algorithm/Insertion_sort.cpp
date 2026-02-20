class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int j = i - 1;
            while(j >= 0 && nums[j] > nums[j + 1]){
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                j--;
            }
        }
        return nums;
    }
};
