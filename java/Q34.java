package java;

import java.util.*;

import java.utils.TreeNode;

/** PathSum II */
public class Q34 {
    /** main backtrack body */
    public static void findPathSum(TreeNode root, int target) {
        if (root == null) {
            System.err.println("Null root pointer");
            return;
        }

        List<TreeNode> path = new ArrayList<TreeNode>();
        findPathSum(root, path, target);
    }

    /** backtracking helper function */
    private static void findPathSum(TreeNode root, List<TreeNode> path, int sum) {

        sum -= root.val;
        path.add(root);

        // if current node root is leaf node
        boolean isLeaf = root.left == null && root.right == null;
        if (isLeaf && sum == 0) {
            printPath(path);
        }

        // if current root node is not leaf node
        if (root.left != null) {
            findPathSum(root.left, path, sum);
        }
        if (root.right != null) {
            findPathSum(root.right, path, sum);
        }

        // backtracking
        sum += root.val;
        path.remove(path.size() - 1);
    }

    /** print the path */
    private static void printPath(List<TreeNode> path) {
        System.out.print("A path found: ");
        for (TreeNode t : path) {
            System.out.print(t.val + " ");
        }
        System.out.println();
    }

    // ============ testing ===============
    private static void test(String testName, TreeNode root, int target) {
        System.out.println("------" + testName + "------");
        findPathSum(root, target);
    }

    private static void test2() {
        TreeNode root = null;
        test("Test 4", root, 1);
    }

    private static void test3() {
        TreeNode n1 = new TreeNode(4);
        TreeNode n2 = new TreeNode(7);
        TreeNode n3 = new TreeNode(5, n1, n2);
        TreeNode n4 = new TreeNode(12);
        TreeNode root = new TreeNode(10, n3, n4);
        test("Test 3", root, 15);
    }

    private static void test4() {
        TreeNode n1 = new TreeNode(4);
        TreeNode n2 = new TreeNode(7);
        TreeNode n3 = new TreeNode(5, n1, n2);
        TreeNode n4 = new TreeNode(12);
        TreeNode root = new TreeNode(10, n3, n4);
        test("Test 4", root, 22);
    }

    private static void test5() {
        TreeNode root = new TreeNode(1);
        test("Test 5", root, 1);
    }

    public static void main(String[] args) {
        test2();
        test3();
        test4();
        test5();
    }
}
