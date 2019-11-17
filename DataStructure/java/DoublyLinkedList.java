package datastructure;

public class DoublyLinkedList {
    private class Node {
        private int val;
        private Node next;
        private Node prev;

        Node(final int val) {
            this.val = val;
            this.next = null;
            this.prev = null;
        }
    }

    private Node head;
    private Node tail;

    public DoublyLinkedList() {
        this.head = new Node(0);
        this.tail = new Node(0);

        head.next = tail;
        tail.prev = head;
    }

    public void pushBack(int num) {
        Node node = new Node(num);

        node.prev = tail.prev;
        node.next = tail;

        tail.prev.next = node;
        tail.prev = node;
    }

    public void pushFront(int num) {
        Node node = new Node(num);

        node.prev = head;
        node.next = head.next;

        head.next.prev = node;
        head.next = node;
    }

    public void pushSequence(int num) {
        Node temp = findNextNode(num);
        Node node = new Node(num);

        node.prev = temp.prev;
        node.next = temp;

        if (temp.prev != null) temp.prev.next = node;
        temp.prev = node;
    }

    public void deleteNode(final int num) {
        Node node = findNode(num);
        if (node == null) {
            throw new IllegalArgumentException("해당하는 원소가 없습니다.");
        }

        if (node.prev != null) node.prev.next = node.next;
        if (node.next != null) node.next.prev = node.prev;
    }

    private Node findNode(final int num) {
        Node node = head.next;
        while (node.next != null) {
            if (node.val == num) {
                return node;
            }
            node = node.next;
        }
        return null;
    }

    private Node findNextNode(final int num) {
        Node node = head;
        while (node.next != null) {
            if (node.next.val > num) {
                return node.next;
            }
            node = node.next;
        }
        return node;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node node = head.next;
        while (node.next != null) {
            sb.append(node.val).append(' ');
            node = node.next;
        }
        return sb.toString();
    }
}
