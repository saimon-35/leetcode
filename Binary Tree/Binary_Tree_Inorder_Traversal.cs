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
    void Traverse(List<int>res, TreeNode root){
        if(root == null) return;
        Traverse(res, root.left);
        res.Add(root.val);
        Traverse(res, root.right);
    }

    public IList<int> InorderTraversal(TreeNode root) {
        List<int> result = new List<int>();
        Traverse(result, root);
        return result;
    }
}
