import utils.java.ListNode;

/**
 * Delete duplicate nodes in a sorted linked list.
 * e.g. input: 1->2->3->3->4->4->5, output: 1->2->5
 */
public class Q18_2 {

    /** Iterative */
    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
            // throw new IllegalArgumentException();
        }

        ListNode dummy = new ListNode(-1, head);
        ListNode prev = dummy;

        while (head != null) {
            if (head.next != null && head.next.val == head.val) { // need delete
                while (head.next != null && head.next.val == head.val) {
                    head = head.next;
                }
                prev.next = head.next;
            } else { // not need delete
                prev = prev.next;
            }
            head = head.next;
        }

        return dummy.next;
    }

    /** given by book */
    public static ListNode deleteDuplicates_official(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode dummy = new ListNode(-1, head);
        ListNode prev = dummy;

        while (head != null) {
            ListNode nextNode = head.next;
            boolean needDelete = false;

            if (head.next != null && nextNode.val == head.val) {
                needDelete = true;
            }

            if (!needDelete) {
                prev = head;
                head = head.next;
            } else {
                int value = head.val;
                ListNode toDelNode = head;

                while (toDelNode != null && toDelNode.val == value) {
                    nextNode = toDelNode.next;
                    toDelNode = nextNode;
                }

                if (prev == null) {
                    head = nextNode;
                } else {
                    prev.next = nextNode;
                }

                head = nextNode;
            }
        }
        return dummy.next;
    }

    /** Recursive */
    public static ListNode deleteDuplicatesRecursion(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        if (head.next != null && head.next.val == head.val) {
            while (head.next != null && head.next.val == head.val) {
                head = head.next;
            }
            return deleteDuplicatesRecursion(head.next);
        }
        head.next = deleteDuplicatesRecursion(head.next);
        return head;
    }

    // ================== testing =================
    private static void test(String testName, ListNode head) {
        System.out.println("-------" + testName + "-------");
        ListNode.printList(head);
        ListNode node = deleteDuplicates(head);
        ListNode.printList(node);
    }

    /** duplicates are at middle */
    private static void test1() {
        int[] vals = new int[] { 1, 2, 3, 3, 4, 4, 5 };
        ListNode head = ListNode.createList(vals);
        test("test1", head);
    }

    /** duplicates are at beginning */
    private static void test2() {
        int[] vals = new int[] { 1, 1, 2, 2, 3, 4, 5 };
        ListNode head = ListNode.createList(vals);
        test("test2", head);
    }

    /** duplicates are at end */
    private static void test3() {
        int[] vals = new int[] { 1, 2, 3, 4, 4, 5, 5 };
        ListNode head = ListNode.createList(vals);
        test("test3", head);
    }

    /** No duplicates */
    private static void test4() {
        int[] vals = new int[] { 1, 2, 3, 4, 5 };
        ListNode head = ListNode.createList(vals);
        test("test4", head);
    }

    /** All different duplicates */
    private static void test5() {
        int[] vals = new int[] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
        ListNode head = ListNode.createList(vals);
        test("test5", head);
    }

    /** All same duplicates */
    private static void test6() {
        int[] vals = new int[] { 1, 1, 1, 1, 1 };
        ListNode head = ListNode.createList(vals);
        test("test6", head);
    }

    /** One node */
    private static void test7() {
        ListNode head = new ListNode(1);
        test("test7", head);
    }

    /** nullptr */
    private static void test8() {
        ListNode head = null;
        test("test8", head);
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
    }
}
