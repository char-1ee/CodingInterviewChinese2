import utils.java.ListNode;

/**
 * Print the k-th last node in linked list
 */
public class Q22 {

    public static ListNode findKthToTail(ListNode head, int k) {
        if (k == 0) {
            System.err.println("-1: k cannot be zero");
            return new ListNode(-1);
        }
        if (head == null) {
            System.err.println("-2: List cannot be null");
            return new ListNode(-2);
        }

        ListNode curr = head;
        int cnt = k;
        while (curr != null && cnt > 0) {
            curr = curr.next;
            cnt--;
        }
        if (cnt > 0) {
            System.err.println("-3: k is larger than list length");
            return new ListNode(-3);
        }

        ListNode res = head;
        while (curr != null) {
            curr = curr.next;
            res = res.next;
        }
        return res;
    }

    private static void test(String testname, int[] vals, int k) {
        System.out.println("-----" + testname + "-----");

        ListNode head = ListNode.createList(vals);
        ListNode.printList(head);
        int x = findKthToTail(head, k).val;
        System.out.println("Find k-th last: " + x);
    }

    public static void main(String[] args) {
        int[] list = new int[] { 1, 2, 3, 4, 5 };

        // Functional testing
        test("test 1", list, 1);
        test("test 2", list, 5);
        test("test 3", list, 2);

        // Edge case testing
        test("test 4", list, 0);
        test("test 5", list, 6);
        test("test 5", null, 2);
    }
}
