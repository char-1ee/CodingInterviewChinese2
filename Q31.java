import java.util.*;

/**
 * Given push-in stack sequence, tell a pop-out stack sequence is valid.
 */
public class Q31 {
    public static boolean isPopOrder(int[] pushOrder, int[] popOrder) {   
        if (pushOrder == null || popOrder == null || pushOrder.length != popOrder.length) {
            return false;
        }

        Stack<Integer> stack = new Stack<Integer>();
        int i = 0; // ptr to push order arr
        int j = 0; // ptr to pop order arr

        while (j < popOrder.length) {
            while (stack.empty() || stack.peek() != popOrder[j]) {
                if (i == pushOrder.length) {
                    break;
                }
                stack.push(pushOrder[i++]);
            }

            if (stack.peek() != popOrder[j]) {
                break;
            }

            stack.pop();
            j++;
        }

        return stack.empty() && j == popOrder.length;
    }

    private static void test(String testName, int[] pushOrder, int[] popOrder, boolean expected) {
        System.out.print(testName + ": ");
        boolean res = isPopOrder(pushOrder, popOrder);
        if (res == expected) {
            System.out.println("Pass");
        } else {
            System.out.println("FAILED");
        }
    }

    private static void test1() {
        int[] pushOrder = new int[] {1, 2, 3, 4, 5};
        int[] popOrder = new int[] {4, 5, 3, 2, 1};
        test("Test 1", pushOrder, popOrder, true);
    }

    private static void test2() {
        int[] pushOrder = new int[] {1, 2, 3, 4, 5};
        int[] popOrder = new int[] {4, 3, 5, 1, 2};
        test("Test 2", pushOrder, popOrder, false);
    }

    private static void test3() {
        int[] pushOrder = new int[] {1};
        int[] popOrder = new int[] {1};
        test("Test 3", pushOrder, popOrder, true);
    }

    private static void test4() {
        int[] pushOrder = new int[] {1};
        int[] popOrder = new int[] {2};
        test("Test 4", pushOrder, popOrder, false);
    }

    private static void test5() {
        test("Test 5", null, null, false);
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
