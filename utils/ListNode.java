package utils;
public class ListNode {

    public int val;
    public ListNode next;

    public ListNode(int x) {
        val = x;
    }

    public ListNode(int x, ListNode next) {
        val = x;
        this.next = next;
    }

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
}
