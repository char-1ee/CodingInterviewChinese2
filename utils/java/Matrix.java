package utils.java;

public class Matrix {
    public long a00;
    public long a01;
    public long a10;
    public long a11;

    public Matrix(long a00, long a01, long a10, long a11) {
        this.a00 = a00;
        this.a01 = a01;
        this.a10 = a10;
        this.a11 = a11;
    } 

    public static Matrix multiply(Matrix m1, Matrix m2) {
        return new Matrix(
            m1.a00 * m2.a00 + m1.a01 * m2.a10,
            m1.a00 * m2.a01 + m1.a01 * m2.a11,
            m1.a10 * m2.a00 + m1.a11 * m2.a10,
            m1.a11 * m2.a01 + m1.a11 * m2.a11
        );
    }
    
    // Transpose, Ax = B
}
