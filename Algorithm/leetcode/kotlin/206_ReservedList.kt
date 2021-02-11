package com.huisam.kotlin.leetcode

import java.util.*

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

fun reverseList(head: ListNode?): ListNode? {
    if (head == null) return null
    val stack = Stack<ListNode>()
    var now = head
    while (now != null) {
        stack.add(now)
        now = now.next
    }
    val ans = stack.peek()
    while (stack.isNotEmpty()) {
        now = stack.pop()
        now.next = if (stack.isNotEmpty()) stack.peek() else null
    }
    return ans
}

fun main() {
    val node5 = ListNode(5)
    val node4 = ListNode(4).apply { next = node5 }
    val node3 = ListNode(3).apply { next = node4 }
    val node2 = ListNode(2).apply { next = node3 }
    val node1 = ListNode(1).apply { next = node2 }

    var reserveNodes = reverseList(node1)
    while (reserveNodes != null) {
        print(" ${reserveNodes.`val`}")
        reserveNodes = reserveNodes.next
    }
    val ans = reverseList(null)
    println(ans)
}
