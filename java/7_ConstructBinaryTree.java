package java;

import java.utils.TreeNode;

/**
 * Construct a binary tree according to its inorder traversal and preorder
 * traversal.
 */
class Q7 {
    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        assert inorder.length == preorder.length;
        assert preorder != null && inorder != null;

        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    public static TreeNode buildTree(
            int[] preorder, int startPreIdx, int endPreIdx,
            int[] inorder, int startInIdx, int endInIdx) {
        if (startPreIdx >= endPreIdx || startInIdx >= endInIdx)
            return null;

        int rootVal = preorder[startPreIdx];
        int rootIdx = 0;
        // we can also use hash map to build index-value reflection in advance to reduce
        // search costs
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[rootIdx] == rootVal)
                break;
        }

        int leftTreeSize = rootIdx - startInIdx + 1;
        TreeNode root = new TreeNode(rootVal);
        root.left = buildTree(
                preorder, startPreIdx + 1, startPreIdx + leftTreeSize,
                inorder, startInIdx, rootIdx - 1);
        root.right = buildTree(
                preorder, startPreIdx + leftTreeSize + 1, endPreIdx,
                inorder, rootIdx + 1, endInIdx);
        return root;
    }
}

/**
 * Preorder: 1, 2, 4, 7, 3, 5, 6, 8
 * Inorder: 4, 7, 2, 1, 5, 3, 8, 6
 * 
 * 1) For preorder array, the root value is arr[0]
 * 2) As we know root value, we find the index in root in inorder array
 * 3) Recursion of 1) and 2)
 * 
 * 1 | 2 4 7 | 3 5 6 8
 * root | left subtree | right subtree
 * 4 7 2 | 1 | 5 3 8 6
 * left subtree | root | right subtree
 */
