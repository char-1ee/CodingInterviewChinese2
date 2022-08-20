package java;

import java.util.*;

/**
 * Implement a queue with two stacks.
 * Two methods: appendTail() and deleteHead()
 */
class Q9 {
    public static void main(String[] args) {
        CQueue<Integer> cq = new CQueue<Integer>();
        // pop from empty queue
        // cq.deleteHead();

        // push in empty queue
        for (int i = 0; i < 5; i++) {
            cq.appendTail(i);
        }
        System.out.println(cq);

        // pop from non-empty queue
        cq.deleteHead();
        cq.deleteHead();
        System.out.println(cq);

        // push in non-empty queue
        cq.appendTail(5);
        cq.appendTail(6);
        System.out.println(cq);
    }
}

class CQueue<T> {
    private Stack<T> in; // stack for enqueue
    private Stack<T> out; // stack for dequeue

    public CQueue() {
        in = new Stack<T>();
        out = new Stack<T>();
    }

    public void appendTail(T t) {
        in.push(t);
    }

    public T deleteHead() {
        if (in.empty() && out.empty()) {
            throw new NoSuchElementException("Queue underflow");
        }
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    @Override
    public String toString() {
        return Arrays.toString(in.toArray()) + "\n" + Arrays.toString(out.toArray()) + "\n";
    }
}
