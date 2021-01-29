package com.huisam.kotlin.leetcode

/**
 * LeetCode Problem
 * @see <a href="https://leetcode.com/problems/contains-duplicate-ii/">문제링크</a>
 */
fun containsNearbyDuplicate(nums: IntArray, k: Int): Boolean {
    val hash = mutableMapOf<Int, Int>()
    nums.forEachIndexed {index, num ->
        if (hash.containsKey(num) && index - hash[num]!! <= k) {
            return true
        }
        hash[num] = index
    }
    return false
}

fun main() {
    println(containsNearbyDuplicate(intArrayOf(1, 2, 3, 1, 2, 3), 2))
}