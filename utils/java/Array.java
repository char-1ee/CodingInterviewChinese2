package utils.java;

import java.util.Random;

public class Array {
    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private static int partition(int[] arr, int start, int end) {
        if (arr == null || start >= end) {
            throw new IllegalArgumentException("partition(): invalid input");
        }

        Random rand = new Random();
        int index = rand.nextInt(end - start + 1) + start;
        swap(arr, index, start);

        int i = start;
        int j = end + 1;
        int pivot = arr[start];
        while (true) {
            while (arr[++i] < pivot) {
                if (i == end) {
                    break;
                }
            }
            while (arr[--j] > pivot) {
                if (j == start) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(arr, i, j);
        }
        swap(arr, start, j);
        return j;
    }

    public static int partition(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException();
        }
        return partition(arr, 0, arr.length - 1);
    }

    public static void printIterable(int[] arr) {
        if (arr == null || arr.length == 0) {
            return;
        }
        System.out.println("Print the list");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
