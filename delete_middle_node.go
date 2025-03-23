package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
	if head.Next == nil {
		return nil
	}
	current := head
	total := 0
	for current != nil {
		total++
		current = current.Next
	}
	average := total / 2
	current = head
	index := 0
	for index+1 != average {
		current = current.Next
		index++
	}
	current.Next = current.Next.Next
	return head
}
