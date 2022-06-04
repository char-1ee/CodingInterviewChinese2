package java;

import java.utils.ComplexListNode;

/**
 * Clone a complex linked list. ComplexListNode refers to utils.ComplexListNode.
 * 
 * To track sibling node, we can maintain a HashMap<N, N'>, or we can
 * 
 * divide a complex problem into sub-problems by steps.
 * (original listnode N, copy listnode N')
 * - copy N to N.next = N'
 * - copy N'.sibling = N.sibling.next
 * - divide the whole list apart
 */
public class Q35 {
    public static ComplexListNode clone(ComplexListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            ComplexListNode res = head.clone();
            res.sibling = head.sibling;
            return res;
        }

        copyNodes(head);
        connectSiblings(head);
        return divide(head);
    }

    /** Step 1 */
    private static void copyNodes(ComplexListNode head) {
        ComplexListNode curr = head;
        while (curr != null) {
            ComplexListNode copy = curr.clone();
            curr.next = copy;
            curr = copy.next;
        }
    }

    /** Step 2 */
    private static void connectSiblings(ComplexListNode head) {
        ComplexListNode curr = head;
        while (curr != null) {
            ComplexListNode copy = curr.next;
            copy.sibling = curr.sibling;
            curr = copy.next;
        }
    }

    /** Step 3 */
    private static ComplexListNode divide(ComplexListNode head) {
        ComplexListNode curr = head;
        ComplexListNode dummy = new ComplexListNode(-1, head);
        ComplexListNode node = dummy;
        while (curr != null) {
            node.next = curr.next;
            curr = curr.next.next;
            node = node.next;
        }
        return dummy.next;
    }

    // ============== testing ===============
    private static void test(String testname, ComplexListNode head) {
        System.out.println("======" + testname + "======");
        ComplexListNode.printlist(head);

        ComplexListNode cloneList = clone(head);

        System.out.println("----- Clone list -----");
        ComplexListNode.printlist(cloneList);
    }

    private static void test1() {
        ComplexListNode n5 = new ComplexListNode(5);
        ComplexListNode n4 = new ComplexListNode(4, n5);
        ComplexListNode n3 = new ComplexListNode(3, n4);
        ComplexListNode n2 = new ComplexListNode(2, n3);
        ComplexListNode n1 = new ComplexListNode(1, n2);

        n1.sibling = n3;
        n2.sibling = n5;
        n4.sibling = n2;

        test("Test 1", n1);
    }

    private static void test2() {
        ComplexListNode n5 = new ComplexListNode(5);
        ComplexListNode n4 = new ComplexListNode(4, n5);
        ComplexListNode n3 = new ComplexListNode(3, n4);
        ComplexListNode n2 = new ComplexListNode(2, n3);
        ComplexListNode n1 = new ComplexListNode(1, n2);

        n2.sibling = n5;
        n3.sibling = n3;
        n4.sibling = n2;

        test("Test 2", n1);
    }

    private static void test3() {
        ComplexListNode n5 = new ComplexListNode(5);
        ComplexListNode n4 = new ComplexListNode(4, n5);
        ComplexListNode n3 = new ComplexListNode(3, n4);
        ComplexListNode n2 = new ComplexListNode(2, n3);
        ComplexListNode n1 = new ComplexListNode(1, n2);

        n2.sibling = n4;
        n4.sibling = n2;

        test("Test 3", n1);
    }

    private static void test4() {
        ComplexListNode n1 = new ComplexListNode(1);
        n1.sibling = n1;

        test("Test 4", n1);
    }

    private static void test5() {
        test("Test 5", null);
    }

    /** unit testing */
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}