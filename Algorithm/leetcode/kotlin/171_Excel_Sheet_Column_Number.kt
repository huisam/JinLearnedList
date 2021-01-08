package com.huisam.kotlin.leetcode

/**
 * LeetCode Problem
 * @see <a href="https://leetcode.com/problems/excel-sheet-column-number/">문제링크</a>
 */
class Solution2 {
    fun titleToNumber(s: String): Int {
        return s.toCharArray().fold(0) { total, num ->
            total * 26 + (num - 'A' + 1)
        }
    }
}

fun main() {
    println(Solution2().titleToNumber("ZY"))
}
