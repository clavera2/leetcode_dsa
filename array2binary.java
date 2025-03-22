/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return recursive(nums, 0, nums.length-1);
    }

    private static TreeNode recursive(int[] nums, int left_index, int right_index) {
        if (left_index > right_index) return null;
        if (left_index == right_index) {
            TreeNode n = new TreeNode(nums[left_index]);
            return n;
        }
        int middle = (left_index+right_index)/2;
        TreeNode n = new TreeNode(nums[middle]);
        n.left = recursive(nums, left_index, middle-1);
        n.right = recursive(nums, middle+1, right_index);
        return n;
    }
}