// LeetCode : Concatenation of Array
// Problem link : https://leetcode.com/problems/concatenation-of-array/description/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> ans = nums;
        for(auto u : nums) ans.push_back(u);
        return ans;
    }
};
