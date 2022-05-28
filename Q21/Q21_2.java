package Q21;
/**
 * Apply Strategy Pattern: 
 * https://refactoring.guru/design-patterns/strategy
 * shorturl.at/bftS2
 * 
 * Strategy + ConcreteStrategy + Context + Client
 */

/** Strategy */
interface ReorderStrategy {
    public boolean reorderRule(int[] arr, int idx);
}

/** ConcreteStrategy */
class OddEvenReorderStrategy implements ReorderStrategy {
    @Override
    public boolean reorderRule(int[] arr, int idx) {
        return (arr[idx] & 0x1) == 0;
    }
}

// Context
class Context {
    private ReorderStrategy reorderStrategy = null;

    public Context(ReorderStrategy reorderStrategy) {
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
            while (i < j && !reorderStrategy.reorderRule(arr, i))
                i++;
            while (i < j && reorderStrategy.reorderRule(arr, j))
                j--;

            if (i < j) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        return arr;
    }
}

/** Client */
public class Q21_2 {
    public static void main(String[] args) {
        int[] arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

        ReorderStrategy reorderStrategy = new OddEvenReorderStrategy();
        Context instance = new Context(reorderStrategy);

        int[] newArr = instance.reorderOddEven(arr);

        for (int num : newArr) {
            System.out.print(num + " ");
        }
    }
}
