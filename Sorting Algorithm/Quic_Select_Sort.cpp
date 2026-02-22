class Solution {
public:
    int sol(int s, int e, int k, vector<int>&arr){
        if(s < e){
            int pivot = arr[e];
            int left = s;
            for(int i = s; i < e; i++){
                if(arr[i] < pivot){
                    int temp = arr[left];
                    arr[left] = arr[i];
                    arr[i] = temp;
                    left++;
                }
            }
            arr[e] = arr[left];
            arr[left] = pivot;
            if(arr.size() - k == left) return pivot;
            if(arr.size() - k > left) return sol(left + 1, e, k, arr);
            else return sol(s, left - 1, k, arr); 
        }
        return arr[s];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int ans = sol(0, nums.size() - 1, k, nums);
        return ans;
    }
};
