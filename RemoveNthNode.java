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
    public ListNode removeNthFromEnd(ListNode head, int n) {
                if (head == null) {
            return null;
        } else if (head.next == null) {
            return null;
        }
        Stack<ListNode> stack = new Stack<>();
        ListNode current = head;
        while (current != null) {
            stack.push(current);
            current = current.next;
        }
        Stack<ListNode> second = new Stack<>();
        int i = 0;
        while (!stack.isEmpty()) {
            i++;
            if (i == n) {
                stack.pop();
            } else {
                second.push(stack.pop());
            }
        }
        ListNode newList = second.pop();
        current = newList;
        while (!second.isEmpty()) {
            current.next = second.pop();
            current = current.next;
        }
        current.next = null;
        return newList;   
    }
}