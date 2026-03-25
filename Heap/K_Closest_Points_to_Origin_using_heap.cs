public class Solution
{
    public int[][] KClosest(int[][] points, int k)
    {
        // Max-heap to store points and their squared distances
        // heap[0] is a dummy element to use 1-based indexing
        List<(int[] point, int dist)> heap = new List<(int[], int)>();
        heap.Add((new int[] { 0, 0 }, 0)); // dummy element

        // Helper function: compute squared distance from origin
        int DistSq(int[] p) => p[0] * p[0] + p[1] * p[1];

        // Bubble up a node at index i to maintain max-heap property
        void BubbleUp(int i)
        {
            while (i > 1 && heap[i].dist > heap[i / 2].dist) // if child > parent
            {
                // Swap child with parent
                (heap[i], heap[i / 2]) = (heap[i / 2], heap[i]);

                // Move to parent's index
                i = i / 2;
            }
        }

        // Bubble down a node at index i to maintain max-heap property
        void BubbleDown(int i)
        {
            int n = heap.Count - 1; // last valid index (ignore dummy)

            while (2 * i <= n)
            {
                int child = 2 * i; // left child

                // Choose the larger child (for max-heap)
                if (child + 1 <= n && heap[child + 1].dist > heap[child].dist)
                {
                    child = child + 1; // right child is bigger
                }

                // If parent >= largest child, heap property satisfied
                if (heap[i].dist >= heap[child].dist)
                    break;

                // Swap parent with largest child
                (heap[i], heap[child]) = (heap[child], heap[i]);

                // Continue bubbling down
                i = child;
            }
        }

        // Build initial max-heap with first k points
        for (int i = 0; i < k; i++)
        {
            heap.Add((points[i], DistSq(points[i])));
            BubbleUp(heap.Count - 1); // maintain max-heap
        }

        // Process remaining points
        for (int i = k; i < points.Length; i++)
        {
            int dist = DistSq(points[i]);

            // If new point is closer than the farthest point (heap[1])
            if (dist < heap[1].dist)
            {
                heap[1] = (points[i], dist); // replace root
                BubbleDown(1);               // maintain max-heap
            }
        }

        // Extract k closest points from heap (ignore dummy at index 0)
        int[][] result = new int[k][];
        for (int i = 0; i < k; i++)
        {
            result[i] = heap[i + 1].point;
        }

        return result;
    }
}
