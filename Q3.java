
/**
 * Q3_1: find duplicates in a given array in-place.
 *      1. Sorting: O(NlogN), O(1)
 *      2. HashMap: O(N), O(N)
 *      3. Indexing swaps: O(N), O(1)
 * Q3_2: find duplicates in a given array in-place and must not change the original array.
 *      1. Auxiliary array (index reflections): O(N), O(N)
 *      2. Binary search on [1, n-1]: O(NlogN), O(1)
 * 
 */
public class Q3 {
    /**
     * Time O(n): for every number we can find its position in maximum 2 swaps
     * Space O(1): in-place swap
     * 
     * @param arr         the array with length n and elements in [0, n-1]
     * @param duplication the array contains result duplicate element, pass back to
     *                    caller as reference
     * @return true if found duplicates, false if invalid input or no duplicates
     */
    public static boolean findDuplicate1(int[] arr, int[] duplication) {

        // only when array is initalized as Object reference type, arr[] can be null;
        // otherwise arr[] can only be said empty
        if (arr == null || arr.length == 0) {
            duplication[0] = -1;
            return false;
        }

        // check invalid element
        for (int num : arr) {
            if (num < 0 || num > arr.length - 1) {
                duplication[0] = -1;
                return false;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            while (arr[i] != i) {
                if (arr[i] == arr[arr[i]]) {
                    duplication[0] = arr[i];
                    return true;
                } else {
                    int tmp = arr[i];
                    arr[i] = arr[tmp];
                    arr[tmp] = tmp;
                }
            }
        }
        duplication[0] = -1;
        return false;
    }

    /**
     * Time O(NlogN): O(logN) * O(n)
     * Space: O(1): in-space without change original array
     * 
     * @param arr the array with length n+1 and elements in [1, n]
     * @return one duplicate number in arr, otherwise -1
     */
    public static int findDuplicate2(int[] arr) {
        if (arr == null || arr.length == 0)
            return -1;

        // similarly, check invalid element as above (omit here)

        int left = 1, right = arr.length - 1;
        while (right >= left) {

            // int mid = (right - left) >> 1 + left
            int mid = left + (right - left) / 2;
            int count = countInRange(arr, left, mid);

            // terminal condition when left==right==a certain number has duplicates
            if (left == right) {
                if (count > 1)
                    return left;
                else // otherwise no duplicates
                    break;
            }

            if (count > mid - left + 1)
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }

    /**
     * Count the occurrence of number in [lo, hi]
     * Time in O(N)
     */
    private static int countInRange(int[] arr, int lo, int hi) {
        if (arr.length == 0)
            return 0;
        int cnt = 0;
        for (int num : arr) {
            if (num >= lo && num <= hi)
                cnt++;
        }
        return cnt;
    }
}
