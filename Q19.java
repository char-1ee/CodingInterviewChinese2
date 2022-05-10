/**
 * Regex engine for '*' and '.'.
 */
public class Q19 {
    public static boolean regexMatch(String text, String pattern) {
        // assert pattern is valid
        if (text == null || pattern == null) {
            return false;
        }

        char[] texts = text.toCharArray();
        char[] patterns = pattern.toCharArray();

        return helper(texts, 0, patterns, 0);
    }

    private static boolean helper(char[] text, int i, char[] pattern, int j) {

        // I. when text ends, pattern ends
        if (i == text.length && j == pattern.length) {
            return true;
        }

        // II. when text not ends, pattern ends
        if (i != text.length && j == pattern.length) {
            return false;
        }

        // III. when text ends, pattern not ends || when text not ends, pattern not ends

        // 1. when next ch in pattern is '*'
        if (j < pattern.length - 1 && pattern[j + 1] == '*') {

            // when text ends
            if (i == text.length) {
                return false;
            }
            // when text not ends
            else {
                // when the ch before '*' matches text
                if (text[i] == pattern[j] || (pattern[j] == '.' && i != text.length)) {
                    return helper(text, i + 1, pattern, j + 2) // enter next state of DFA
                            || helper(text, i + 1, pattern, j) // stay in current state of DFA
                            || helper(text, i, pattern, j + 2); // omit the '*'
                }
                // when the ch before '*' not matches text, omit "a*"
                else {
                    return helper(text, i, pattern, j + 2);
                }
            }
        }

        // 2. when next ch in pattern is not '*'
        if (i == text.length) {
            return false;
        } else if (text[i] == pattern[j] || (pattern[j] == '.' && i != text.length)) { // when match then go on
            return helper(text, i + 1, pattern, j + 1);
        }

        // if no-match happens, return false;
        return false;
    }

    // ==================== test =========================
    private static void test(String testName, String text, String pattern, boolean expected) {
        System.out.println("------" + testName + "------");
        if (regexMatch(text, pattern) == expected) {
            System.out.println("Passed.");
        } else {
            System.out.println("FAILED.");
        }
    }

    public static void main(String[] args) {
        test("test1", "aaa", ".*", true);
        test("test2", "aab", "c*a*b", true);
        test("test3", "aaca", "ab*a*c*a", true);
        test("test4", "aaba", "ab*a*c*a", false);
        test("test5", "bbbba", ".*a*a", true);
        test("test6", "bcbbabab", ".*a*a", false);
    }
}
