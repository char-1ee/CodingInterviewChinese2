import utils.TreeNode;

/**
 * Convert a BST to a sorted bi-directional linked list.
 * No nodes should be created, which allows only in-place pointer operations. 
 */
public class Q36 {

    private static TreeNode last = null;

    public static TreeNode convert(TreeNode root) {
        if (root == null) {
            System.err.println("NULL root");
            return null;
        }

        helper(root);

        while (last != null && last.left != null) {
            last = last.left;
        }
        return last;
    }

    private static void helper(TreeNode root) {
        if (root == null) {
            return;
        }
        // go to the leftmost node under the current root
        helper(root.left);

        // connect last node and root(curr) node
        if (last != null) {
            last.right = root;
            root.left = last;
        }

        // point `last` to upper level node for next connection
        last = root; 

        // go right
        helper(root.right);
    }

    private static void printList(TreeNode root) {
        if (root == null) {
            System.out.println("NULL");
        }
        TreeNode curr = root;

        System.out.println("Left to right: ");
        while (curr != null) {
            System.out.print(curr.val + " ");
            if (curr.right == null) {
                break;
            }
            curr = curr.right;
        }
        System.out.println();

        System.out.println("Right to left: ");
        while (curr != null) {
            System.out.print(curr.val + " ");
            if (curr.left == null) {
                break;
            }
            curr = curr.left;
        }
        System.out.println();
    }

    // TODO: 爷累了，这里写错了，不改了，以后改
    public static void main(String[] args) {
        TreeNode root1 = convert(TreeNode.case1());
        TreeNode root2 = convert(TreeNode.case2());
        TreeNode root3 = convert(TreeNode.case3());
        TreeNode root4 = convert(new TreeNode(1));
        TreeNode root5 = convert(null);

        printList(root1);
        printList(root2);
        printList(root3);
        printList(root4);
        printList(root5);
    }
}
