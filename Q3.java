
/**
 * 1. Sorting O(NlogN), O(1)
 * 2. HashMap O(N), O(N)
 * 3. Indexing O(N), O(1)
 */
public class Q3 {
    /**
     * Time O(n): for every number we can find its position in maximum 2 swaps
     * Space O(1): in-place swap
     * 
     * @param arr         the array may contain duplicates
     * @param duplication the array contains result duplicate element, pass back to
     *                    caller as reference
     * @return true if found duplicates, false if invalid input or no duplicates
     */
    public static boolean findDuplicate(int[] arr, int[] duplication) {

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
}
