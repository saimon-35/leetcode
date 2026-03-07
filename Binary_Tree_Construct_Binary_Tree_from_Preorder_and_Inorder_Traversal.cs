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
    Dictionary<int, int> mp = new Dictionary<int, int>();
    void mapping(int[] inorder){
        for(int i = 0; i < inorder.Length; i++) mp[inorder[i]] = i;
    }
    TreeNode build(int[] preorder, int prestart, int preend, int instart, int inend){
        if(prestart > preend || instart > inend) return null;
        int rootval = preorder[prestart];
        TreeNode root = new TreeNode(rootval);
        int index = mp[rootval];
        int leftsize = index - instart;
        root.left = build(preorder, prestart + 1, leftsize + prestart, instart, index - 1);
        root.right = build(preorder, prestart + leftsize + 1, preend, index + 1, inend);
        return root;
    }
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        mapping(inorder);
        return build(preorder, 0, preorder.Length - 1, 0, inorder.Length - 1);
    }
}
