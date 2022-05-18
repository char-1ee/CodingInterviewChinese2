import java.util.Stack;

import utils.ListNode;

/**
 * Print out the mirror of a binary tree.
 */
public class Q27 {
    /** Recursion */
    public static void mirrorRecursive(TreeNode root) {
        if (root == null) { // nullptr
            return;
        }
        if (root.left == null && root.right == null) { // single node tree
            return;
        }

        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        if (root.left != null) {
            mirrorRecursive(root.left);
        }
        if (root.right != null) {
            mirrorRecursive(root.right);
        }
    }

    /** Iterative */
    public static void mirrorIterative(TreeNode root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        while (!s.empty()) {
            TreeNode n = s.pop();

            TreeNode tmp = n.left;
            n.left = n.right;
            n.right = tmp;

            if (n.left != null) {
                s.push(n.left);
            }
            if (n.right != null) {
                s.push(n.right);
            }
        }
    }

    public static void main(String[] args) {
        // TODO
        // test1();
        // test2();
        // test3();
        // test4();
        // test5();
    }
}
