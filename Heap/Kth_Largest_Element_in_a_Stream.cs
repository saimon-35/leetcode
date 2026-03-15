public class KthLargest
{
    // Min-heap to store at most k largest elements
    // Index 0 is unused so that heap becomes 1-indexed
    List<int> heap = new List<int>();

    // k value (we keep the k largest elements)
    int p;

    public KthLargest(int k, int[] nums)
    {
        // Store k
        p = k;

        // Insert dummy value so heap indexing starts from 1
        heap.Insert(0, 0);

        // Insert initial numbers using Add()
        // This ensures heap property is maintained
        foreach (int x in nums)
        {
            Add(x);
        }
    }

    public int Add(int val)
    {
        // If heap size is smaller than k, simply insert the value
        if (heap.Count - 1 < p)
        {
            heap.Add(val);

            // Restore heap property by moving element upward
            BubbleUp(heap.Count - 1);
        }
        else
        {
            // If heap already has k elements,
            // compare with the smallest element (root of min heap)
            if (heap[1] < val)
            {
                // Replace the root with new value
                heap[1] = val;

                // Restore heap property by moving element downward
                BubbleDown(heap, 1);
            }
        }

        // Root of the min heap is the kth largest element
        return heap[1];
    }

    // Moves a node upward until heap property is restored
    void BubbleUp(int i)
    {
        while (i > 1 && heap[i] < heap[i / 2])
        {
            // Swap with parent
            (heap[i], heap[i / 2]) = (heap[i / 2], heap[i]);

            // Move to parent index
            i = i / 2;
        }
    }

    // Moves a node downward until heap property is restored
    void BubbleDown(List<int> heap, int i)
    {
        int n = heap.Count - 1; // because index 0 is unused

        while (2 * i <= n)
        {
            int child = 2 * i; // left child

            // Choose the smaller child (important for min heap)
            if (child + 1 <= n && heap[child + 1] < heap[child])
            {
                child = child + 1;
            }

            // If parent is already smaller than child, heap property satisfied
            if (heap[i] <= heap[child])
            {
                break;
            }

            // Swap parent with smaller child
            (heap[i], heap[child]) = (heap[child], heap[i]);

            // Continue bubbling down
            i = child;
        }
    }
}

/*
Your KthLargest object will be instantiated and called as such:

KthLargest obj = new KthLargest(k, nums);
int param_1 = obj.Add(val);
*/
