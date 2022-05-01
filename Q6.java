import java.util.Stack;
import utils.ListNode;

/**
 * Given a head of linked list, reversely print out value of every node.
 * (Assume noy allowed to modify original list)
 */
public class Q6 {

    /** Stack */
    public static void printListReverse(ListNode head) {
        if (head == null)
            return;
        Stack<Integer> stack = new Stack<Integer>();
        ListNode curr = head;
        while (curr != null) {
            stack.push(curr.val);
            curr = curr.next;
        }
        while (!stack.empty()) {
            System.out.print(stack.pop() + " ");
        }
        System.out.println();
    }

    /** Recursion */
    public static void printListReverseRecursive(ListNode head) {
        if (head == null)
            return;
        if (head.next != null)
            printListReverseRecursive(head.next);
        System.out.print(head.val);
        return;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1, null);
        ListNode l2 = null;
        ListNode l3 = new ListNode(0);
        l3 = ListNode.insert(l3, 1);
        l3 = ListNode.insert(l3, 2);
        l3 = ListNode.insert(l3, 3);
        l3 = ListNode.insert(l3, 4);
        printListReverse(l1);
        printListReverse(l2);
        printListReverse(l3);
    }
}
