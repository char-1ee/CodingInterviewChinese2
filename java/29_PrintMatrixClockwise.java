package java;

/**
 * Print matrix in clockwise order.
 */
class Q29 {
    public static void printMatrixClockwise(int[][] matrix) {
        if (matrix == null) {
            System.err.println("Empty matrix");
            return;
        }

        int m = matrix.length, n = matrix[0].length;
        int start = 0; // start index of a matrix loop (col = row = start)

        // divide problem into print matrix by outer circles
        while (m > 2 * start && n > 2 * start) {
            printMatrixCircular(matrix, m, n, start);
            start++;
        }
        System.out.println();
    }

    // print matrix in outer circle spiral order
    public static void printMatrixCircular(int[][] matrix, int nRows, int nCols, int start) {
        int endX = nCols - 1 - start;
        int endY = nRows - 1 - start;

        // from left to right
        for (int i = start; i <= endX; i++) {
            System.out.print(" " + matrix[start][i]);
        }

        // from up to down
        if (start < endY) {
            for (int i = start + 1; i <= endY; i++) {
                System.out.print(" " + matrix[i][endX]);
            }
        }

        // from right to left
        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; i--) {
                System.out.print(" " + matrix[endY][i]);
            }
        }

        // from down to up
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; i--) {
                System.out.print(" " + matrix[i][endY]);
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix1 = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
        int[][] matrix2 = { { 1, 2, 3, 4, 5, 6 } };
        int[][] matrix3 = { { 1 }, { 2 }, { 3 }, { 4 } };

        printMatrixClockwise(matrix1);
        printMatrixClockwise(matrix2);
        printMatrixClockwise(matrix3);
    }
}
