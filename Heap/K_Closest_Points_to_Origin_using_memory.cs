public class Solution
{
    public int[][] KClosest(int[][] points, int k)
    {
        // List to store each point and its distance from origin
        List<((int x, int y), int dist)> list = new List<((int, int), int)>();

        // Loop through all points
        foreach (var p in points)
        {
            int x = p[0];   // x coordinate
            int y = p[1];   // y coordinate

            // Calculate distance from origin (0,0)
            int dist = x * x + y * y;

            // Add point and its distance to the list
            // Duplicates are allowed because List does not enforce unique keys
            list.Add(((x, y), dist));
        }

        // Sort the list based on distance (ascending order)
        var sorted = list.OrderBy(p => p.dist);

        // Take first k closest points
        // Convert them back to jagged array format
        int[][] result = sorted
            .Take(k)
            .Select(p => new int[] { p.Item1.x, p.Item1.y })
            .ToArray();

        // Return the result
        return result;
    }
}
