package com.huisam.kotlin.leetcode

import java.util.*

/**
 * LeetCode Problem
 * @see <a href="https://leetcode.com/problems/task-scheduler/">문제링크</a>
 */
class Solution {
    fun leastInterval(tasks: CharArray, n: Int): Int {
        val record = mutableMapOf<Char, Int>().withDefault { 0 }
            .apply {
                for (task in tasks) {
                    put(task, getValue(task) + 1)
                }
            }
        val queue = PriorityQueue<Int> { o1, o2 -> o2 - o1 }
        for (task in record.keys) {
            queue.add(record[task])
        }

        var answer = 0
        while (!queue.isEmpty()) {
            var time = 0
            val temp = mutableListOf<Int>()
            for (i in (0..n)) {
                if (!queue.isEmpty()) {
                    temp.add(queue.remove() - 1)
                    time++
                }
            }
            temp.filterTo(queue) { it > 0 }
            answer += if (queue.isEmpty()) time else n + 1
        }

        return answer
    }
}

fun main() {
    println(Solution().leastInterval(charArrayOf('A', 'A', 'A', 'B', 'B', 'B'), 2))
}