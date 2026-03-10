public class Solution {
    List <int> vec = new List<int>();
    void sol(IList<IList<int>> subsets,int idx, int[] nums){
        if(idx == nums.Length){
            subsets.Add(new List<int>(vec));
            return;
        }
        vec.Add(nums[idx]);
        sol(subsets, idx + 1, nums);
        vec.RemoveAt(vec.Count - 1);
        sol(subsets, idx + 1, nums);
    }
    public IList<IList<int>> Subsets(int[] nums) {
        IList<IList<int>> subsets = new List<IList<int>>();
        sol(subsets, 0, nums);
        return subsets;
    }
}
