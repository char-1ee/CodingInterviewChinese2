package java;

/**
 * Check whether a string is numeric.
 * e.g. "+100", "5e2", "-123", "3.1415", "-1E-16"
 */
public class Q20 {

    private static int i = 0; // string pointer

    /**
     * ============================ method 1 ===============================
     * A[.[B]][e|EC] or .B[e|EC], where A and C are signed int, B is unsigned int
     */
    public static boolean isNumeric(String s) {
        if (s == null || s.length() == 0) {
            return false;
        }

        i = 0; // global pointer

        scanSpaces(s);

        // A
        boolean numeric = scanInteger(s);

        // B
        if (i < s.length() && s.charAt(i) == '.') {
            i++;
            // 1) 200.
            // 2) 200.33
            // 3) .33
            numeric = scanUnsignedInteger(s) || numeric;
        }

        // C
        if (i < s.length() && (s.charAt(i) == 'E' || s.charAt(i) == 'e')) {
            i++;
            numeric = scanInteger(s) && numeric;
        }

        scanSpaces(s);

        // when no error is encountered AND reach the end of string
        return numeric && i == s.length();
    }

    /** Scan for signed integer part */
    private static boolean scanInteger(String s) {
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            i++;
        }
        return scanUnsignedInteger(s);
    }

    /** Scan for unsigned integer part */
    private static boolean scanUnsignedInteger(String s) {
        int prev = i; // pointer before scanning
        while (i < s.length() && s.charAt(i) <= '9' && s.charAt(i) >= '0') {
            i++;
        }
        return i > prev;
    }

    /** Scan for spaces at the beginning and at the end */
    private static void scanSpaces(String s) {
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }
    }

    /**
     * ============================ method 2 ===============================
     * java.lang.String: boolean matches(String regex)
     */
    public static boolean isNumeric_2(String s) {
        if (s == null || s.length() < 1) {
            return false;
        }

        // integer part but no fractional part
        String regex1 = "(\\s)*[+-]?\\d+(\\.\\d*)?([eE][+-]?\\d+)?(\\s)*";
        // fractional part but no integer part
        String regex2 = "(\\s)*[+-]?\\d*(\\.\\d+)([eE][+-]?\\d+)?(\\s)*";

        // if have exponent, it cannot be empty before e/E part
        return s.matches(regex1) || s.matches(regex2);
    }

    // ============================ testing ================================
    private static void test(String testName, String s, boolean expected) {
        System.out.println("---------" + testName + "---------");
        if (isNumeric(s) == expected) {
            System.out.println("isNumberic 1 Passed.");
        } else {
            System.out.println("isNumberic 1 FAILED.");
        }

        if (isNumeric_2(s) == expected) {
            System.out.println("isNumberic 2 Passed.");
        } else {
            System.out.println("isNumberic 2 FAILED.");
        }
    }

    public static void main(String[] args) {
        test("Test1", "100", true);
        test("Test2", "123.45e+6", true);
        test("Test3", "+500", true);
        test("Test4", "5e2", true);
        test("Test5", "3.1416", true);
        test("Test6", "600.", true);
        test("Test7", "-.123", true);
        test("Test8", "-1E-16", true);
        test("Test9", "1.79769313486232E+308", true);

        System.out.println();

        test("Test10", "12e", false);
        test("Test11", "1a3.14", false);
        test("Test12", "1+23", false);
        test("Test13", "1.2.3", false);
        test("Test14", "+-5", false);
        test("Test15", "12e+5.4", false);
        test("Test16", ".", false);
        test("Test17", ".e1", false);
        test("Test18", "e1", false);
        test("Test19", "+.", false);
        test("Test20", "", false);
        test("Test21", null, false);
    }
}

/**
 * TODO: Also, we can use DFA to solve this problem,
 * https://zhuanlan.zhihu.com/p/345913593
 */