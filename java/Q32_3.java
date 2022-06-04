package java;

import java.util.*;

import java.utils.TreeNode;

/**
 * Print bianry tree in zigzag order
 */
public class Q32_3 {
    public static void printInZigZagOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        int curr = 0, next = 1;
        List<Stack<TreeNode>> s = new ArrayList<Stack<TreeNode>>();
        s.add(new Stack<TreeNode>());
        s.add(new Stack<TreeNode>());
        s.get(curr).push(root);

        while (!s.get(0).empty() || !s.get(1).empty()) {
            TreeNode t = s.get(curr).pop();
            System.out.print(t.val + " ");

            if (curr == 0) {
                if (t.left != null) {
                    s.get(next).push(t.left);
                }
                if (t.right != null) {
                    s.get(next).push(t.right);
                }
            } else {
                if (t.right != null) {
                    s.get(next).push(t.right);
                }
                if (t.left != null) {
                    s.get(next).push(t.left);
                }
            }

            if (s.get(curr).empty()) {
                System.out.println();
                curr = 1 - curr;
                next = 1 - next;
            }
        }
    }

    public static void main(String[] args) {
        TreeNode root5 = null;
        TreeNode root4 = new TreeNode(1);
        TreeNode root3 = TreeNode.case3();
        TreeNode root2 = TreeNode.case2();
        TreeNode root1 = TreeNode.case1();

        printInZigZagOrder(root1);
        printInZigZagOrder(root2);
        printInZigZagOrder(root3);
        printInZigZagOrder(root4);
        printInZigZagOrder(root5);
    }
}
