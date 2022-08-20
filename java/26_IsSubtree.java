package java;

import java.utils.TreeNode;

/**
 * Given binary tree A and B, check whether B is the subtree of A.
 * 
 * - 1. find same root node nodeA == nodeB
 * - 2. compare subtree(nodeA) = subtree(nodeB)
 * 
 * or we can traverse two trees and compare strings by KMP
 */

class Q26 {

    private static final double EPSILON = 0.0000001d;

    /** 1. find same node with rootB in A */
    public static boolean hasSubtree(TreeNode root1, TreeNode root2) {
        boolean flag = false;

        if (root1 != null && root2 != null) {
            if (equals(root1.val, root2.val)) {
                flag = isSubtree(root1, root2);
            }
            if (!flag) {
                flag = hasSubtree(root1.left, root2);
            }
            if (!flag) {
                flag = hasSubtree(root1.right, root2);
            }
        }
        return flag;

        // alternatively
        // if (root1 == null || root2 == null) {
        // return false;
        // }
        // return hasSubtree(root1, root2)
        // || hasSubtree(root1.left, root2)
        // || hasSubtree(root1.right, root2);
    }

    /** 2. Compare subtree(nodeA) and subtree(rootB) */
    private static boolean isSubtree(TreeNode root1, TreeNode root2) {
        if (root2 == null) {
            return true;
        }
        if (root1 == null) {
            return false;
        }
        if (!equals(root1.val, root2.val)) {
            return false;
        }

        return isSubtree(root1.left, root2.left) && isSubtree(root1.right, root2.right);
    }

    private static boolean equals(double x, double y) {
        return Math.abs(x - y) < EPSILON;
    }

    public static void main(String[] args) {
        TreeNode a1 = new TreeNode(4);
        TreeNode a2 = new TreeNode(7);
        TreeNode a3 = new TreeNode(2, a1, a2);
        TreeNode a4 = new TreeNode(9);
        TreeNode a5 = new TreeNode(8, a4, a3);
        TreeNode a6 = new TreeNode(7);
        TreeNode a7 = new TreeNode(8, a5, a6);

        TreeNode b1 = new TreeNode(9);
        TreeNode b2 = new TreeNode(2);
        TreeNode b3 = new TreeNode(8, b1, b2);

        if (hasSubtree(a7, b3)) {
            System.out.println("Tree A contains full tree B");
        } else {
            System.out.println("Wrong");
        }
    }
}
