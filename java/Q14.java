package java;

/**
 * Given a rope with length n, cut the rope into m segments and notations are
 * k[0],
 * k[1], k[2]...k[m]. Find the max product of k[0], k[1]...k[m].
 * (m > 1 and n, m are integers)
 */
public class Q14 {

    /**
     * DP: time O(n^2), space O(n);
     */
    public static int cutRopeByDP(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int[] product = new int[n + 1]; // dp array
        product[0] = 1;
        product[1] = 1; // no cut, unit length
        product[2] = 2; // no cut, unit length
        product[3] = 3; // no cut, unit length

        // the native approach
        for (int i = 4; i <= n; i++) {
            int max = 0;
            for (int j = 1; j <= i / 2; j++) {
                max = Math.max(max, product[j] * product[i - j]);
            }
            product[i] = max;
        }

        // the general approach
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= i / 2; j++) {
        // product[i] = Math.max(product[i], product[j] * product[i - j]);
        // }
        // }

        return product[n];
    }

    /**
     * Greedy: time O(1), space O(1);
     * Proved by inequality of arithemtic mean.
     */
    public static int cutRopeByGreedy(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int a = n / 3; // times of three
        if (n % 3 == 1) {
            a--;
        }
        int b = (n - a * 3) / 2; // times of two

        return (int) (Math.pow(3, a) * Math.pow(2, b));
    }

    public static void main(String[] args) {
        System.out.println("DP testing");
        System.out.println("Test case 1: " + cutRopeByDP(5));
        System.out.println("Test case 2: " + cutRopeByDP(7));
        System.out.println("Test case 3: " + cutRopeByDP(10));

        System.out.println("Greedy testing");
        System.out.println("Test case 1: " + cutRopeByGreedy(5));
        System.out.println("Test case 2: " + cutRopeByGreedy(7));
        System.out.println("Test case 3: " + cutRopeByGreedy(10));
    }
}
