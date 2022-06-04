package java.utils;
public class ListNode {

    public int val;
    public ListNode next;

    public ListNode() {
        val = 0;
        next = null;
    }

    public ListNode(int x) {
        val = x;
    }

    public ListNode(int x, ListNode next) {
        val = x;
        this.next = next;
    }

    /** Insert a new node in the end of the list */
    public static ListNode insert(ListNode node, int x) {
        ListNode newNode = new ListNode(x);
        if (node == null) {
            node = newNode;
        } else {
            ListNode curr = node;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = node;
        }
        return node;
    }

    /** Print out the list */
    public static void printList(ListNode head) {
        if (head == null) {
            System.out.println("Empty list");
            return;
        }

        while (head != null) {
            System.out.print(head.val);
            head = head.next;
            if (head != null) {
                System.out.print("->");
            }
        }
        System.out.println();
    }

    /** Create a list given a val array */
    public static ListNode createList(int[] values) {
        if (values == null) {
            return null;
        }

        ListNode head = new ListNode();
        ListNode curr = head;
        for (int value : values) {
            ListNode node = (value == -1) ? new ListNode() : new ListNode(value);
            curr.next = node;
            curr = node;
        }
        return head.next;
    }

    public static void main(String[] args) {
        int[] vals = new int[] {1, 2, 3, 4, 5};
        ListNode node = createList(vals);
        printList(node);
    }
}
