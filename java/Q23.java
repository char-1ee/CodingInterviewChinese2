package java;

import java.utils.ListNode;

/**
 * If there exists loop in linked list, find the entry node of the loop.
 */
public class Q23 {

    public static ListNode entryNodeOfLoop(ListNode head) {
        ListNode meetingNode = meetingNode(head);

        // if no loop || head is null || single
        if (meetingNode == null) {
            return null;
        }

        // find the number of nodes in loop
        int cnt = 1;
        ListNode node = meetingNode;
        while (node.next != meetingNode) { // must use node.next to check
            node = node.next;
            cnt++;
        }

        ListNode p1 = head;
        ListNode p2 = head;
        for (int i = 0; i < cnt; i++) {
            p1 = p1.next;
        }
        while (p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }

    /**
     * Check whether there exists loop in linked list.
     */
    private static ListNode meetingNode(ListNode head) {
        if (head == null || head.next == null) {
            System.err.println("Input list cannot be null or single");
            return null;
        }
        ListNode slow = head.next;
        ListNode fast = slow.next;
        while (slow != null && fast != null) {
            if (slow == fast) {
                return fast;
            }
            slow = slow.next;
            fast = fast.next;
            if (fast != null) {
                fast = fast.next;
            }
        }
        return null; // if no loop
    }

    private static void test1() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        node5.next = node3;

        System.out.println("test 1: ");
        System.out.println("entry node of loop: " + entryNodeOfLoop(node1).val);
    }

    private static void test2() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);

        System.out.println("test 2: ");
        System.out.println("entry node of loop: " + entryNodeOfLoop(node1));
    }

    private static void test3() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        node5.next = node5;

        System.out.println("test 3: ");
        System.out.println("entry node of loop: " + entryNodeOfLoop(node1).val);
    }

    private static void test4() {
        ListNode node = new ListNode(1);
        System.out.println("test 4: ");
        System.out.println("entry node of loop: " + entryNodeOfLoop(node));
    }

    private static void test5() {
        ListNode nullHead = null;
        System.out.println("test 5: ");
        System.out.println("entry node of loop: " + entryNodeOfLoop(nullHead));
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
