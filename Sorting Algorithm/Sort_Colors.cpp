class Solution {
public:
    void sortColors(vector<int>& nums) { 
        map<int, int> m; 
        for(auto u : nums){
            m[u]++;
        }
        int i = 0;
        for(auto u : m){
            while(u.second--){
                nums[i] = u.first;
                i++;
            }
        }
    }
};
