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
    public bool HasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        targetSum = targetSum - root.val;
        if(root.left == null && root.right == null && targetSum == 0) return true;
        if(HasPathSum(root.left, targetSum)) return true;
        if(HasPathSum(root.right, targetSum)) return true;
        targetSum = targetSum + root.val;
        return false;
    }
}
