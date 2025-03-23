package main

import "math"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {
	num_list := make([]int, 0)
	current := head
	for current != nil {
		num_list = append(num_list, current.Val)
		current = current.Next
	}
	i, j, max_sum := 0, len(num_list)-1, 0
	for j > i {
		max_sum = int(math.Max(float64(max_sum), float64(num_list[i]+num_list[j])))
		i++
		j--
	}
	return max_sum
}
