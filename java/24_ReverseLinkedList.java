package java;

import java.utils.ListNode;

/**
 * reverse a linked list
 */
class Q24 {
    public static ListNode reverseList_01(ListNode head) {
        if (head == null || head.next == null) {
            System.err.println("Invalid input");
            return head;
        }

        ListNode curr = head;
        ListNode prev = null;
        while (curr != null) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    public static ListNode reverseList_02(ListNode head) {
        ListNode newHead = null;
        ListNode curr = head;
        ListNode prev = null;

        while (curr != null) {
            ListNode tmp = curr.next;
            if (tmp == null) {
                newHead = curr;
            }
            curr.next = prev;
            prev = curr;
            curr = tmp;

        }
        return newHead;
    }

    private static void test(String testname, ListNode head) {
        System.out.println("------" + testname + "------");
        ListNode.printList(head);
        ListNode newHead = reverseList_02(head);
        ListNode.printList(newHead);
    }

    private static void test1() {
        int[] vals = new int[] { 1, 2, 3, 4, 5 };
        ListNode head = ListNode.createList(vals);
        test("Test 1", head);
    }

    private static void test2() {
        ListNode head = new ListNode(1);
        test("Test 2", head);
    }

    private static void test3() {
        ListNode head = null;
        test("Test 3", head);
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
    }
}
