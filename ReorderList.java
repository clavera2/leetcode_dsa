/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
    Deque<ListNode> dq = new LinkedList<>();
        ListNode current = head;
        while (current != null) {
            dq.add(current);
            current = current.next;
        }
        Stack<ListNode> first = new Stack<>();
        Stack<ListNode> second = new Stack<>();
        while (!dq.isEmpty()) {
            first.push(dq.pollFirst());
            if (!dq.isEmpty()) {
                first.push(dq.pollLast());
            }
        }
        while (!first.isEmpty()) {
            second.push(first.pop());
        }
        while (!second.isEmpty()) {
            ListNode c = second.pop();
            if (second.isEmpty()) {
                c.next = null;
                break;
            }
            c.next = second.peek();
        }
    }
}