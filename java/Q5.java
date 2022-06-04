package java;

/**
 * Replace every space in a String with "%20".
 * 
 * Hints: When we merge arrays/strings or replace certain elements in array
 * (in-place), if iterating from start to end it may duplicately move elements.
 * If iterating backwards, we can reduce operations on array elements.
 * 
 */
public class Q5 {

    /** O(n^2), using auxiliary space */
    public static String replaceSpaces_slow(String s) {
        if (s == null)
            throw new NullPointerException("Input string cannot be null");
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                sb.append("%20");
            } else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }

    /**
     * O(n), backward two-pointers, in-place (memory coverage)
     * Assume there input string has enough extensive upper boundary
     **/
    public static void replaceSpaces(char[] s) {
        if (s == null)
            throw new NullPointerException("Input string cannot be null");

        int cnt = 0; // number of spaces
        for (char c : s) {
            if (c == ' ')
                cnt++;
        }
        int oldLen = s.length;
        int newLen = s.length + 2 * cnt;
        for (int i = oldLen - 1, j = newLen - 1; i >= 0 && i < j;) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
            i--;
        }
        return;
    }

    /** Test driver */
    public static void main(String[] args) throws Exception {
        String[] ss = new String[9];
        ss[0] = new String(" helloworld!"); // front
        ss[1] = new String("helloworld! "); // end
        ss[2] = new String("hello world!"); // middle
        ss[3] = new String("hello    world!"); // consecutive
        ss[4] = new String("helloworld"); // no spaces

        ss[5] = new String("");
        ss[6] = new String("    ");
        ss[7] = new String(" ");
        ss[8] = null;

        for (int i = 0; i < ss.length; i++) {
            System.out.println("String " + i + " : " + Q5.replaceSpaces_slow(ss[i]));

            // char[] str = ss[i].toCharArray();
            // char[] str_scaled = new char[1000000];
            // System.arraycopy(str, 0, str_scaled, 0, str.length);
            // Q5.replaceSpaces(str);
            // System.out.println("String " + i + " : " + new String(str_scaled));
        }
    }
}
