
/**
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * - Integers in each row are sorted in ascending from left to right.
 * - Integers in each column are sorted in ascending from top to bottom.
 * 
 */
public class Q4 {
    /**
     * Reduce search space
     * Time: O(m + n)
     * Space: O(1)
     */
    public static boolean findInMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;

        int row = matrix.length, col = matrix[0].length;
        if (target < matrix[0][0] || target > matrix[row][col])
            return false;

        for (int i = col - 1, j = 0; i >= 0 && j < row;) {
            if (matrix[j][i] == target) {
                return true;
            } else if (matrix[j][i] > target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
}

/**
 * The key to the time complexity analysis is noticing that, on every iteration
 * (during which we do not return true) either row or col is is
 * decremented/incremented exactly once. Because row can only be decremented mm
 * times and col can only be incremented nn times before causing the while loop
 * to terminate, the loop cannot run for more than n+mn+m iterations. Because
 * all other work is constant, the overall time complexity is linear in the sum
 * of the dimensions of the matrix.
 */