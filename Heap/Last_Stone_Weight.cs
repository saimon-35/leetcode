public class Solution
{
    public int LastStoneWeight(int[] stones)
    {
        // PriorityQueue in C# is a min-heap by default.
        // We simulate a max-heap by using negative priority.
        PriorityQueue<int, int> maxHeap = new PriorityQueue<int, int>();

        // Insert all stones into the heap
        foreach (int x in stones)
        {
            maxHeap.Enqueue(x, -x); // larger stone → higher priority
        }

        // Continue smashing stones until fewer than 2 remain
        while (maxHeap.Count >= 2)
        {
            // Take the two largest stones
            int x = maxHeap.Dequeue();
            int y = maxHeap.Dequeue();

            // Smash them
            int res = x - y;

            // If they are not equal, the remaining stone goes back to the heap
            if (res != 0)
            {
                maxHeap.Enqueue(res, -res);
            }
        }

        // If no stones remain, return 0
        if (maxHeap.Count == 0)
            return 0;
        else
            return maxHeap.Dequeue(); // last remaining stone
    }
}
