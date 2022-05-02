import utils.Matrix;

/**
 * Q10_1: Find the Nth in Finbonacci sequence
 * Q10_2: A frog jump in stairs
 */
public class Q10 {

    /**
     * Time: O(n), every node is iterated once.
     */
    public static long finbonacci(int n) {
        if (n < 2)
            return n;
        long fibNMinus1 = 0;
        long fibNMinus2 = 1;
        long fibN = 0;
        for (int i = 2; i <= n; i++) {
            fibN = fibNMinus1 + fibNMinus2;
            fibNMinus2 = fibNMinus1;
            fibNMinus1 = fibN;
        }
        return fibN;
    }

    /** 
     * Time: O(logN) 
     * [f(n),   f(n-1)] = [1, 1] ^(n-1)
     * [f(n-1), f(n-2)]   [1, 0]
     */
    public static long finbonacci2(int n) {
        if (n < 2)
            return n;
        Matrix m = matrixPower(n - 1);
        return m.a00;
    }

    private static Matrix matrixPower(int n) {
        assert n > 0;
        Matrix matrix = new Matrix(1, 1, 1, 0);
        if (n == 1) {
            matrix = new Matrix(1, 1, 1, 0);
        } else if (n % 2 == 0) {
            matrix = matrixPower(n / 2);
            matrix = Matrix.multiply(matrix, matrix);
        } else if (n % 2 == 1) {
            matrix = matrixPower((n - 1) / 2);
            matrix = Matrix.multiply(matrix, matrix);
            matrix = Matrix.multiply(matrix, new Matrix(1, 1, 1, 0));
        }
        return matrix;
    }

}
