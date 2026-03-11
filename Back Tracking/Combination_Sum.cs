public class Solution
{
    List<int> vec = new List<int>();

    void sol(IList<IList<int>> sets, int target, int[] nums, int idx)
    {
        if (idx == nums.Length)
        {
            if (target == 0)
                sets.Add(new List<int>(vec));
            return;
        }

        // include current number
        if (nums[idx] <= target)
        {
            target = target - nums[idx];
            vec.Add(nums[idx]);

            sol(sets, target, nums, idx);

            vec.RemoveAt(vec.Count - 1);
            target = target + nums[idx];
        }

        // skip current number
        sol(sets, target, nums, idx + 1);
    }

    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        IList<IList<int>> ans = new List<IList<int>>();

        sol(ans, target, candidates, 0);

        return ans;
    }
}
