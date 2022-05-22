import java.util.LinkedList;
import java.util.Queue;

import utils.TreeNode;

/**
 * Print binary tree in level order in seperate lines
 */
public class Q32_2 {
    public static void printByLine(TreeNode root) {
        if (root == null) {
            System.out.println("Null pointer");
            return;
        }

        int nextLevelCount = 0;
        int remainLevelCount = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode t = q.poll();
            System.out.print(t.val + " ");
            if (t.left != null) {
                q.offer(t.left);
                nextLevelCount++;
            }
            if (t.right != null) {
                q.offer(t.right);
                nextLevelCount++;
            }
            remainLevelCount--;
            if (remainLevelCount == 0) {
                System.out.println();
                remainLevelCount = nextLevelCount;
                nextLevelCount = 0;
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

        printByLine(root1);
        printByLine(root2);
        printByLine(root3);
        printByLine(root4);
        printByLine(root5);
    }

}
