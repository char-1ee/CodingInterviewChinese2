/**
 * Apply Strategy Pattern: 
 * https://refactoring.guru/design-patterns/strategy
 * shorturl.at/bftS2
 */
interface ReorderStrategy {
    public boolean reorderRule(int[] arr, int idx);
}

class OddEvenReorderStrategy implements ReorderStrategy {
    @Override
    public boolean reorderRule(int[] arr, int idx) {
        return (arr[idx] & 0x1) == 0;
    }
}

public class Q21_2 {
    private ReorderStrategy reorderStrategy;

    public Q21_2(ReorderStrategy reorderStrategy) {
        this.reorderStrategy = reorderStrategy;
    }

    public int[] reorderOddEven(int[] arr) {
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

    public static void main(String[] args) {
        int[] arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

        ReorderStrategy reorderStrategy = new OddEvenReorderStrategy();
        Q21_2 instance = new Q21_2(reorderStrategy);

        int[] newArr = instance.reorderOddEven(arr);

        for (int num : newArr) {
            System.out.print(num + " ");
        }
    }
}
