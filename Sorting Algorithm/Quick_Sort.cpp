// worst case O(n * n)
class Solution {
public:
    void QuickSort(int s, int e, vector<int> &arr){
        if(s < e){
            int pivot = arr[e];
            int left = s;
            for(int i = s; i < e; i++){
                if(arr[i] < pivot ){
                    int temp = arr[left];
                    arr[left] = arr[i];
                    arr[i] = temp;
                    left++;
                }
            }
            arr[e] = arr[left];
            arr[left] = pivot;
            QuickSort(s, left - 1, arr);
            QuickSort(left + 1, e, arr);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(0, nums.size() - 1, nums);
        return nums;
    }
};
