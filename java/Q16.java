package java;

/**
 * Implement double Power(double base, int exponent), no overflow, no built-in.
 */
public class Q16 {

    private static boolean INVALID_INPUT = false; // a global flag to indicate invalid input
    private static final double EPSILON = 0.000001d;

    public static double pow(double base, int exponent) { // name a variable clearly

        INVALID_INPUT = false;
        if (doubleEqual(base, 0.0d) && exponent < 0) {
            INVALID_INPUT = true;
            return 0.0d;
        }

        boolean isExponentNegative = false;
        if (exponent < 0) {
            isExponentNegative = true;
            exponent = -exponent;
        }

        double res = powWithUnsignedExponent(base, exponent);
        if (isExponentNegative) {
            res = 1.0d / res;
        }

        return res;
    }

    private static double powWithUnsignedExponent(double base, int exponent) {
        if (doubleEqual(base, 0.0d)) {
            return 0.0d;
        }
        if (exponent == 0) {
            return 1.0d;
        }
        if (exponent == 1) {
            return base;
        }

        // ======== recursion ==========
        double res = powWithUnsignedExponent(base, exponent >> 1);
        res *= res;
        if (exponent % 2 == 1) { // (exponent & 0x1) == 1
            res *= base;
        }

        // ======== iterating ==========
        // double res = 1.0d;
        // while (exponent > 0) {
        // if (exponent % 2 == 1) {
        // res *= base;
        // exponent--;
        // } else {
        // res *= res;
        // exponent /= 2;
        // }
        // }

        return res;
    }

    private static boolean doubleEqual(double a, double b) {
        return Math.abs(a - b) < EPSILON;
    }

    private static void test(String testName, double base, int exponent, double expectedResult, boolean expectedFlag) {
        double res = pow(base, exponent);

        if (doubleEqual(res, expectedResult) && expectedFlag == INVALID_INPUT) {
            System.out.println(testName + " pass ");
        } else {
            System.out.println(testName + " FAILED ");
        }
    }

    public static void main(String[] args) {

        long startTime = System.nanoTime();

        // testing correctness
        test("Test1", 2d, 3, 8.0d, false);
        test("Test2", 2d, -3, 0.125d, false);
        test("Test4", 2d, 0, 1.0d, false);

        test("Test3", -2.0d, 3, -8.0d, false);
        test("Test4", -2.0d, -3, -0.125d, false);
        test("Test4", -2.0d, 0, 1d, false);

        test("Test3", 0d, 3, 0d, false);
        test("Test4", 0d, -3, 0d, true); // invalid input
        test("Test4", 0d, 0, 0d, false);

        // testing performance
        test("Performance testing", 45d, 123, 22138041353571795d, false);

        long endTime = System.nanoTime();

        System.out.println("The time spent: " + (endTime - startTime) / 10000.0d);
    }
}
