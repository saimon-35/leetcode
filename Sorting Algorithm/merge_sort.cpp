class Solution {
public:
    void merge(int s, int m, int e, vector<int>&arr){
        int n1 = m - s + 1;
        int n2 = e - m;
        int L[n1], R[n2];
        for(int i = 0; i < n1; i++) L[i] = arr[s + i];
        for(int i = 0; i < n2; i++) R[i] = arr[m + i + 1];
        // for(int i = 0; i < n1; i++) cout << L[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < n2; i++) cout << R[i] << ' ';
        int i = 0;
        int j = 0;
        int k = s;
        while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }
        else{
            arr[k] = R[j];
            j++;
            k++;
        }
        }
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergesort(int s, int e, vector<int>&arr){
        if(s < e){
            int m = s + (e - s) / 2;
            mergesort(s, m, arr);
            mergesort(m + 1, e, arr);
            merge(s, m, e, arr);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        mergesort(s, e, nums);
        return nums;
    }
};
