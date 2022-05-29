
import utils.java.ListNode;

/**
 * Delete a node in linked list in time O(1).
 */
public class Q18_1 {

    /**
     * Average time: O(1)
     */
    public static ListNode delete(ListNode head, ListNode node) {
        if (head == null || node == null) {
            return null;
        }

        // if node is not tail: O(1)
        if (node.next != null) {
            ListNode nextNode = node.next;
            node.val = nextNode.val;
            node.next = nextNode.next;
        }
        // only one node and delete head node
        else if (head == node) {
            head = head.next;
        }
        // node is tail: O(n)
        else {
            ListNode curr = head;
            while (curr.next != node) {
                curr = curr.next;
            }
            curr.next = null;
        }
        return head;
    }

    // ======================== testing ==============================
    private static void test(ListNode head, ListNode node, String testName) {
        System.out.println("-------" + testName + "-------");
        System.out.println("Node to delete: " + node.val);
        System.out.print("The original list: ");
        ListNode.printList(head);

        head = delete(head, node);

        System.out.print("The result list: ");
        ListNode.printList(head);
    }

    /** Multiple node in list, delete in-list node */
    private static void test1() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        test(node1, node3, "test1");
    }

    /** Multiple node in list, delete tail node */
    private static void test2() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        test(node1, node5, "test2");
    }

    /** Multiple node in list, delete head node */
    private static void test3() {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        test(node1, node1, "test3");
    }

    /** Only one node in list, delete that node */
    private static void test4() {
        ListNode node = new ListNode(1, null);
        test(node, node, "test4");
    }

    /** list is empty */
    private static void test5() {
        ListNode node = new ListNode(-1);
        test(null, node, "test5");
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}

/**
 * -> Delete a node in O(1)
 * -> We have to assume pToBeDelete must be in list, because checking
 * pToBeDelete's existence must cost O(n).
 * So it is delete()'s caller's job to check pToBeDelete's existence.
 * -> Overwrite the pToBeDelete with pToBeDelete->next, then delete
 * pToBeDelete->next: O(1)
 * -> For tail node, we have to iterate to pToBeDelete: O(n)
 * -> Time complexity: ((n - 1)O(1) + O(n)) / n = O(1)
 * 
 * Cases:
 * 1. Multiple nodes, delete from
 * - head
 * - middle
 * - tail
 * 2. Single node, delete head/end
 * 3. nullptr
 */