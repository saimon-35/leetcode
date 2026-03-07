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
    void Traverse(TreeNode root, ref int cnt, ref int ans, int k){
        if(root == null || cnt > k) return;
        Traverse(root.left, ref cnt, ref ans, k);
        cnt++;;
        if(cnt == k) {
            ans = root.val;
            return;
        }
        Traverse(root.right, ref cnt, ref ans, k);
    }
    public int KthSmallest(TreeNode root, int k) {
        int cnt = 0;        
        int ans = 0;
        Traverse(root, ref cnt, ref ans, k);
        return ans;
    }
}
