package com.huisam.kotlin.leetcode

/**
 * LeetCode Problem
 * @see <a href="https://leetcode.com/problems/delete-node-in-a-linked-list/">문제링크</a>
 */
fun deleteNode(node: ListNode?) {
    node?.`val` = node?.next!!.`val`
    node.next = node.next?.next
}

fun main() {
    val first = ListNode(9)
    val second = ListNode(1).apply { next = first }
    val third = ListNode(5).apply { next = second }
    val fourth = ListNode(4).apply { next = third }
    deleteNode(second)
}