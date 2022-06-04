package java.utils;

public class ComplexListNode {
    public int val;
    public ComplexListNode next;
    public ComplexListNode sibling; // point to random node in list or nullptr

    public ComplexListNode(int val) {
        this.val = val;
        this.next = null;
        this.sibling = null;
    }

    public ComplexListNode(int val, ComplexListNode next) {
        this.val = val;
        this.next = next;
        this.sibling = null;
    }

    public static void printlist(ComplexListNode head) {
        ComplexListNode curr = head;
        while (curr != null) {
            System.out.print("curr node: " + curr.val + "   ");
            if (curr.sibling == null) {
                System.out.println("sibling node: NULL ");
            } else {
                System.out.println("sibling node: " + curr.sibling.val);
            }
            curr = curr.next;
        }
    }

    /** Clone node but not copying sibling */
    public ComplexListNode clone() {
        ComplexListNode that = new ComplexListNode(0);
        that.val = this.val;
        that.next = this.next;
        that.sibling = null;
        return that;
    }
}
