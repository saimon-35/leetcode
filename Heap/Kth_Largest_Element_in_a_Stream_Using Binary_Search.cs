public class KthLargest
{
    // List to store the numbers
    List<int> num = new List<int>();

    // k value
    int p;

    public KthLargest(int k, int[] nums)
    {
        // Add all elements from nums into the list
        num.AddRange(nums);

        // Store k
        p = k;

        // Sort the list in ascending order
        num.Sort();

        // Keep only the k largest elements
        if (num.Count > p)
        {
            num.RemoveRange(0, num.Count - p);
        }
    }

    public int Add(int val)
    {
        // If list is empty, simply add the value
        if (num.Count == 0)
        {
            num.Add(val);
            return val;
        }

        // If we already have k elements and the new value
        // is smaller than the smallest among them,
        // it cannot affect the kth largest value
        if (num.Count == p && val < num[0])
        {
            return num[0];
        }
        
        // Binary search to find insert position
        int idx = num.BinarySearch(val);

        if (idx < 0)
        {
            idx = ~idx; // get insertion index
        }

        num.Insert(idx, val);

        // Keep only the k largest elements
        if (num.Count > p)
        {
            num.RemoveRange(0, num.Count - p);
        }

        // The smallest element in the list is the kth largest
        return num[0];
    }
}

/*
Your KthLargest object will be instantiated and called as such:

KthLargest obj = new KthLargest(k, nums);
int param_1 = obj.Add(val);
*/
