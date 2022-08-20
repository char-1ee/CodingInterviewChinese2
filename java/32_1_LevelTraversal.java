package java;

import java.util.LinkedList;
import java.util.Queue;

import java.utils.TreeNode;

/**
 * Print binary tree in level traversal order.
 */
class Q32_1 {
    public static void printFromTopToBottom(TreeNode root) {
        if (root == null) {
            System.out.println("Null root");
            return;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode t = queue.poll();
            System.out.print(t.val + " ");
            if (t.left != null) {
                queue.offer(t.left);
            }
            if (t.right != null) {
                queue.offer(t.right);
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        TreeNode root5 = null;
        TreeNode root4 = new TreeNode(1);
        TreeNode root3 = TreeNode.case3();
        TreeNode root2 = TreeNode.case2();
        TreeNode root1 = TreeNode.case1();

        printFromTopToBottom(root1);
        printFromTopToBottom(root2);
        printFromTopToBottom(root3);
        printFromTopToBottom(root4);
        printFromTopToBottom(root5);
    }
}