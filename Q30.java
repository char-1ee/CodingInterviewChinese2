import java.util.*;

/**
 * Implement minStack:
 * - min() return the min element in stack
 * - push, pop, min in O(1)
 */
public class Q30 {
    public static void main(String[] args) {
        MinStack<Integer> stack = new MinStack<>();
        stack.push(3);
        System.out.println(stack.toString());
        stack.push(4);
        System.out.println(stack.toString());
        stack.push(2);
        System.out.println(stack.toString());
        stack.push(1);
        System.out.println(stack.toString());
        stack.pop();
        System.out.println(stack.toString());
        stack.pop();
        System.out.println(stack.toString());
        stack.push(0);
        System.out.println(stack.toString());
    }
}

class MinStack<T extends Comparable<T>> {

    private Stack<T> stack; // stack for elements
    private Stack<T> minStack; // stack for min elements

    public MinStack() {
        stack = new Stack<T>();
        minStack = new Stack<T>();
    }

    // =========== main methods ============
    public T min() {
        return minStack.peek();
    }

    public void push(T t) {
        stack.push(t);
        if (minStack.size() == 0 || t.compareTo(min()) < 0) {
            minStack.push(t);
        } else {
            minStack.push(min());
        }
    }

    public T pop() {
        if (empty()) {
            throw new IllegalStateException("Stack is empty");
        }
        minStack.pop();
        return stack.pop();
    }

    // =========== helper methods ============
    public T peek() {
        return stack.peek();
    }

    public boolean empty() {
        return stack.empty() && minStack.empty();
    }

    public int size() {
        return stack.size();
    }

    public String toString() {
        return stack.toString() + "\n" + minStack.toString() + "\n";
    }
}

/**
 * If use only one stack to implements minStack,
 * - Using a linked list to keep track of minVal.
 * - Maintain a minVal. Every time pushing, push the minVal into stack at the
 * sametime.
 * 
 * Internal stack: use size()==0 to tell empty rather than empty(), because
 * empty() will throw EmptyStackException.
 */