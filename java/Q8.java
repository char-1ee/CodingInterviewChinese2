package java;

import java.utils.TreeNode;

/**
 * Given a binary tree and a tree node, find its next node in the inorder
 * traversal sequence of this tree.
 */
public class Q8 {
    public static TreeNode nextInorderNode(TreeNode node) {
        if (node == null)
            return null;

        if (node.right != null) { // node has right subtree
            TreeNode t = node.right;
            while (t.left != null) {
                t = t.left;
            }
            return t;
        } else { // node has no right subtree

            // clear and highly generalized
            while (node.parent != null) {
                TreeNode parentNode = node.parent;
                if (parentNode.left == node) {
                    return parentNode;
                }
                node = node.parent;
            }
            return null;
        }
    }
}

/**
 * .
 * ├── If node t has right subtree, nextInorderNode(t) is the leftmost leaf of
 * its right subtree.
 * └── If node t has no right subtree,
 * ├── If t is parent(t)'s left subtree, nextInorderNode(t) is parent(t).
 * └── If t is parent(t)'s right subtree, we traverse upstream
 * ├── until we find a upstream node t', for which t' is in parent(t')'s left
 * subtree, then nextInorderNode(t) is parent(t');
 * └── until for node t', for which parent(t') is null, then t is the last node
 * in inorder sequence of the tree.
 */
