package java;

import java.utils.TreeNode;

/**
 * Check whether a binary tree is Symmetric (same as mirror of self).
 */
class Q28 {
    public static boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isSymmetric(root.left, root.right);
    }

    private static boolean isSymmetric(TreeNode leftNode, TreeNode rightNode) {
        if (leftNode == null && rightNode == null) {
            return true;
        }
        if ((leftNode == null && rightNode != null) || (leftNode != null && rightNode == null)) {
            return false;
        }
        if (leftNode.val == rightNode.val) {
            return isSymmetric(leftNode.left, rightNode.right) && isSymmetric(leftNode.right, rightNode.left);
        } else {
            return false;
        }
    }

    private static void test(String testname, int[] arr, boolean expected) {
        System.out.println("-----" + testname + "------");
        TreeNode root = (arr == null) ? null : TreeNode.createTree(arr);
        boolean res = isSymmetric(root);
        if (expected == res) {
            System.out.println("Pass");
        } else {
            System.out.println("FAILED");
        }
    }

    public static void main(String[] args) {
        int[] n1 = new int[] { 8, 6, 6, 5, 7, 7, 5 }; // valid case
        int[] n2 = new int[] { 6, 6, 6, 6, 6, 6, 6 }; // same values
        int[] n3 = new int[] { 8, 6, 9, 5, 7, 7, 5 }; // invalid case
        int[] n4 = new int[] { 6, 6, 6, 6, 6, 6, -1 }; // invalid case
        int[] n5 = new int[] { 1 }; // single treenode

        test("Test 1", n1, true);
        test("Test 2", n2, true);
        test("Test 3", n3, false);
        test("Test 4", n4, false);
        test("Test 5", n5, true);
        test("Test 6", null, true);
    }
}
