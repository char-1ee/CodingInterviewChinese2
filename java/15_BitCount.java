package java;

/**
 * Given a integer, return the number of bit 1 in its binary form.
 * java.lang.Integer.bitCount(n)
 */
class Q15 {
    public static int numberOf1_01(int n) {
        int mask = 1;
        int cnt = 0;
        while (mask != 0) {
            if ((mask & n) != 0)
                cnt++;
            mask <<= 1;
        }
        return cnt;
    }

    /** n & (n - 1) */
    public static int numberOf1_02(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] testCases = new int[] { 1, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0 };
        for (int i : testCases) {
            System.out.println(numberOf1_02(i) + " == " + Integer.bitCount(i));
        }
    }
}
