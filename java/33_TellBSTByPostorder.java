package java;

/**
 * Given an array of binary tree postorder traversal,
 * tell whether is a binary search tree.
 * Assume all node values are different.
 */
class Q33 {
    public static boolean isBST(int[] seq) {
        if (seq == null || seq.length == 0) {
            System.err.println("Empty sequence");
            return false;
        }

        return isBST(seq, 0, seq.length - 1);
    }

    private static boolean isBST(int[] seq, int left, int right) {
        if (right - left <= 0) {
            return true;
        }

        int rootVal = seq[right];

        // find the left subtree bound
        int i = left;
        for (; i < right; i++) { // noticed that [right] = rootVal
            if (seq[i] > rootVal) {
                break;
            }
        }

        // find the right subtree bound
        int j = i;
        for (; j < right; j++) {
            if (seq[j] < rootVal) {
                return false;
            }
        }

        return isBST(seq, left, j - 1) && isBST(seq, j, right);
    }

    private static void test(String testName, int[] arr, boolean expected) {
        System.out.print(testName + ": ");
        if (isBST(arr) == expected) {
            System.out.println("Passed");
        } else {
            System.out.println("FAILED");
        }
    }

    public static void main(String[] args) {
        int[] testcase1 = { 4, 8, 6, 12, 16, 14, 10 };
        int[] testcase2 = { 4, 6, 7, 5 };
        int[] testcase3 = { 1, 2, 3, 4, 5 };
        int[] testcase4 = { 5, 4, 3, 2, 1 };
        int[] testcase5 = { 1 };

        test("Test 1", testcase1, true);
        test("Test 2", testcase2, true);
        test("Test 3", testcase3, true);
        test("Test 4", testcase4, true);
        test("Test 5", testcase5, true);
        test("Test 6", null, false);
    }
}
