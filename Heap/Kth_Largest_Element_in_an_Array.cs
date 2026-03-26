public class Solution
{
    public int FindKthLargest(int[] nums, int k)
    {
        // Min-heap (1-based indexing, heap[0] is dummy)
        List<int> heap = new List<int>();
        heap.Insert(0, 0); // dummy element at index 0

        // Move element up to maintain min-heap property
        void BubbleUp(int i)
        {
            // While not at root and current < parent (min-heap)
            while (i > 1 && heap[i] < heap[i / 2])
            {
                // Swap with parent
                (heap[i], heap[i / 2]) = (heap[i / 2], heap[i]);

                // Move to parent index
                i = i / 2;
            }
        }

        // Move element down to maintain min-heap property
        void BubbleDown(int i)
        {
            int n = heap.Count - 1; // ignore index 0

            while (2 * i <= n)
            {
                int child = 2 * i; // left child

                // Choose smaller child (important for min-heap)
                if (child + 1 <= n && heap[child + 1] < heap[child])
                {
                    child = child + 1;
                }

                // If parent is already smaller, heap property satisfied
                if (heap[i] <= heap[child])
                {
                    break;
                }

                // Swap parent with smaller child
                (heap[i], heap[child]) = (heap[child], heap[i]);

                // Move down
                i = child;
            }
        }

        // Add element to heap while keeping size = k
        void Add(int val)
        {
            // If heap size is less than k → just add
            if (heap.Count - 1 < k)
            {
                heap.Add(val);
                BubbleUp(heap.Count - 1);
            }
            else
            {
                // If new value is larger than smallest (root)
                if (heap[1] < val)
                {
                    // Replace root (smallest of k largest)
                    heap[1] = val;

                    // Restore heap property
                    BubbleDown(1);
                }
            }
        }

        // Process all numbers
        foreach (int x in nums)
        {
            Add(x);
        }

        // Root of min-heap is the kth largest element
        return heap[1];
    }
}
