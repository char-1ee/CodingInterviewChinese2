package java;

/**
 * Find minimum number in a rotated array.
 */
public class Q11 {
    public static int findMinInRotatedArray(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Input array must not be empty.");
        }

        int n = arr.length;
        int left = 0, right = n - 1;
        int mid = left; // in case there is no rotation

        while (arr[left] >= arr[right]) { // check whether arr is rotated

            if (left + 1 == right) {
                mid = right;
                break;
            }

            mid = left + (right - left) / 2;

            if (arr[left] == arr[right] && arr[mid] == arr[left]) {
                return findMinInRotatedArrayInOrder(arr, left, right);
            }

            if (arr[mid] > arr[left]) { // in front ascending array
                left = mid;
            } else if (arr[mid] < arr[right]) { // in backward ascendiong array
                right = mid;
            }
        }
        return arr[mid];
    }

    private static int findMinInRotatedArrayInOrder(int[] arr, int left, int right) {
        int res = arr[left];
        for (int i = left; i <= right; i++) {
            if (res > arr[i])
                res = arr[i];
        }
        return res;
    }

    public static void main(String[] args) {
        int[] case1 = new int[] { 3, 4, 5, 1, 2 }; // rotated array
        int[] case2 = new int[] { 1, 2, 3, 4, 5 }; // ascending array without rotation
        int[] case3 = new int[] { 1 }; // single element
        int[] case4 = new int[] { 1, 0, 1, 1, 1 }; // rotated array with same element
        int[] case5 = null; // nullptr

        int test1 = findMinInRotatedArray(case1);
        int test2 = findMinInRotatedArray(case2);
        int test3 = findMinInRotatedArray(case3);
        int test4 = findMinInRotatedArray(case4);
        int test5 = findMinInRotatedArray(case5);

        System.out.println(test1 + " " + test2 + " " + test3 + " " + test4 + " " + test5);
    }
}
