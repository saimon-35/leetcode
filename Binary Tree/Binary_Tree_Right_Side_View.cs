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
    public IList<int> RightSideView(TreeNode root) {
        if(root == null) return new List<int>();
        Queue<TreeNode> q = new Queue<TreeNode>();
        IList<int> see = new List<int>();
        see.Add(root.val);
        q.Enqueue(root);
        while(q.Count() > 0){
            int size = q.Count();
            bool flag = false;
            for(int i = 0; i < size; i++){
                TreeNode temp = q.Peek();
                q.Dequeue();
                if(temp.right != null){
                    q.Enqueue(temp.right);
                    if(flag == false){
                        see.Add(temp.right.val);
                        flag = true;
                    }
                }
                if(temp.left != null){
                    q.Enqueue(temp.left);
                    if(flag == false){
                        see.Add(temp.left.val);
                        flag = true;
                    }
                }

            }
        }
        return see;
    }
}
