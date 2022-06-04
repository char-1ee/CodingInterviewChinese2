package java;

import java.util.Stack;

import java.utils.TreeNode;

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

    // ============== test ================
    private static void test(String testName, int[] vals) {
        System.out.println("------" + testName + "------");
        TreeNode root = TreeNode.createTree(vals);
        TreeNode.printTree(root);

        System.out.println("test for recursion");
        mirrorRecursive(root);
        TreeNode.printTree(root);

        System.out.println("test for iteration");
        mirrorIterative(root);
        TreeNode.printTree(root);
    }

    public static void main(String[] args) {
        int[] v1 = new int[] { 8, 6, 10, 5, 7, 9, 11 };
        int[] v2 = new int[] { 8, 7, -1, 6, -1, 5, -1, 4, -1 };
        int[] v3 = new int[] { 8, -1, 7, -1, 6, -1, 5, -1, 4 };
        int[] v4 = new int[] { 8 };
        int[] v5 = new int[] {};

        test("Test 1", v1);
        test("Test 2", v2);
        test("Test 3", v3);
        test("Test 4", v4);
        test("Test 5", v5);
    }
}
