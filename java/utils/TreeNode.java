package java.utils;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode parent;

    public TreeNode() {}
    public TreeNode(int x) { val = x; }
    public TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x; 
        this.left = left;
        this.right = right;
    }

    /** Print current node, left child, right child */
    private static void printTreeNode(TreeNode root) {
        if (root == null) {
            System.out.println("Empty node");
        } else {
            System.out.print("This node: " + root.val);

            if (root.left != null) {
                System.out.print(" left child: " + root.left.val);
            } else {
                System.out.print(" no left child ");
            }

            if (root.right != null) {
                System.out.print(" right child: " + root.right.val);
            } else {
                System.out.print(" no right child ");
            }
        }
        System.out.println();
    }

    /** print all tree nodes */
    public static void printTree(TreeNode root) {
        printTreeNode(root);
        if (root != null) {
            if (root.left != null) {
                printTreeNode(root.left);
            }
            if (root.right != null) {
                printTreeNode(root.right);
            }
        }
    }

    /** Create a binary tree according to int array */
    // TODO: cannot resolve left-skew tree and right-skew problems
    public static TreeNode createTree(int[] vals) {
        if (vals.length == 0) {
            return null;
        }

        if (vals.length < 2) {
            return new TreeNode(vals[0]);
        }

        TreeNode root = createTree(vals, 0);
        return root;
    }

    private static TreeNode createTree(int[] vals, int idx) {
        if (idx > vals.length - 1) {
            return null;
        }
        if (vals[idx] == -1) {
            return null;
        }

        TreeNode root = new TreeNode(vals[idx]);
        root.left = createTree(vals, 2 * idx + 1);
        root.right = createTree(vals, 2 * idx + 2);
        return root;
    }

    /** Get a complete binary tree. */
    public static TreeNode case1() {
        TreeNode n1 = new TreeNode(5);
        TreeNode n2 = new TreeNode(7);
        TreeNode n3 = new TreeNode(9);
        TreeNode n4 = new TreeNode(11);
        TreeNode n5 = new TreeNode(6, n1, n2);
        TreeNode n6 = new TreeNode(10, n3, n4);
        TreeNode n7 = new TreeNode(8, n5, n6);
        return n7;
    }

    /** Get a left-skew binary tree */
    public static TreeNode case2() {
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2, n1, null);
        TreeNode n3 = new TreeNode(3, n2, null);
        TreeNode n4 = new TreeNode(4, n3, null);
        TreeNode n5  = new TreeNode(5, n4, null);
        return n5;
    }

    /** Get a right-skew binary tree */
    public static TreeNode case3() {
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2, null, n1);
        TreeNode n3 = new TreeNode(3, null, n2);
        TreeNode n4 = new TreeNode(4, null, n3);
        TreeNode n5  = new TreeNode(5, null, n4);
        return n5;
    }

    /** unti testing */
    public static void main(String[] args) {
        System.out.println("------ printTree ---------");
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3, n1, n2);
        TreeNode n4 = new TreeNode(4, n3, null);
        printTree(n4);

        System.out.println("------ createTree ---------");
        int[] vals = new int[] { 4, 3, -1, 1, 2 };
        TreeNode root = createTree(vals);
        printTree(root);
    }
}
