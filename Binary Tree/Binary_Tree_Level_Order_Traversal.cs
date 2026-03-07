/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        if(root == null) return new List<IList<int>>();
        IList<IList<int>> result = new List<IList<int>>();
        result.Add(new List<int> {root.val});
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count() != 0){
            IList<int> numbers = new List<int>();
            int size = q.Count();
            while(size != 0){
            TreeNode temp = q.Peek();
            q.Dequeue();
            if(temp.left != null){
                q.Enqueue(temp.left);
                numbers.Add(temp.left.val);
            }
            if(temp.right != null){
                q.Enqueue(temp.right);
                numbers.Add(temp.right.val);
            }
            size--;
        }
        if(numbers.Count() != 0) result.Add(numbers);
        }
        return result;
    }
}
