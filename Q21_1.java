
/**
 * Given an array, arrange all odd number in front and even number in end.
 */
public class Q21_1 {

    /** two pointer swaps */
    public static int[] reorderOddEven(int[] arr) {
        if (arr == null) {
            throw new IllegalArgumentException("Array cannot be null");
        }
        if (arr.length < 2) {
            return arr;
        }

        for (int i = 0, j = arr.length - 1; i < j;) {
            while (i < j && (arr[i] & 0x1) != 0)
                i++;
            while (i < j && (arr[j] & 0x1) == 0)
                j--;

            if (i < j) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        return arr;
    }

    private static void test(String testname, int[] arr) {
        System.out.println("--------" + testname + "--------");
        System.out.println("test case: ");
        printArray(arr);

        int[] A = reorderOddEven(arr);

        System.out.println("solution: ");
        printArray(A);
    }

    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr1 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
        int[] arr2 = new int[] { 1, 3, 7, 5, 2, 6, 4, 8 };
        int[] arr3 = new int[] { 8, 6, 4, 2, 1, 3, 5, 7 };
        int[] arr4 = new int[] { 1 };
        int[] arr5 = null;

        test("Test 1", arr1);
        test("Test 2", arr2);
        test("Test 3", arr3);
        test("Test 4", arr4);
        test("Test 5", arr5);
    }
}
