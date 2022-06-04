package java;

import java.utils.ListNode;

/**
 * Merge two ascending sorted lists into one ascending list.
 */
public class Q25 {

    /** Recursion */
    public static ListNode mergeSortedList(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }

        ListNode node = null;
        if (list1.val < list2.val) {
            node = list1;
            node.next = mergeSortedList(list1.next, list2);
        } else {
            node = list2;
            node.next = mergeSortedList(list1, list2.next);
        }
        return node;
    }

    private static void test(String testname, ListNode list1, ListNode list2) {
        System.out.println("------" + testname + "------");
        ListNode.printList(list1);
        ListNode.printList(list2);
        // ListNode node = mergeSortedList_iteration(list1, list2);
        ListNode node = mergeSortedList(list1, list2);
        ListNode.printList(node);
    }

    private static void test1() {
        int[] v1 = new int[] { 1, 3, 5, 7 };
        int[] v2 = new int[] { 2, 4, 6, 8 };
        ListNode list1 = ListNode.createList(v1);
        ListNode list2 = ListNode.createList(v2);
        test("Test 1", list1, list2);
    }

    private static void test2() {
        int[] v1 = new int[] { 1, 3, 5, 7 };
        ListNode list1 = ListNode.createList(v1);
        test("Test 2", list1, null);
    }

    private static void test3() {
        ListNode list1 = new ListNode(1);
        ListNode list2 = new ListNode(2);
        test("Test 3", list1, list2);
    }

    private static void test4() {
        int[] v1 = new int[] { 1, 3, 5, };
        int[] v2 = new int[] { 1, 3, 5 };
        ListNode list1 = ListNode.createList(v1);
        ListNode list2 = ListNode.createList(v2);
        test("Test 4", list1, list2);
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
    }
}
