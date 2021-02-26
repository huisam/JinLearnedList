package com.huisam.kotlin.leetcode

/**
 * leetCode Problem
 * @see <a href="https://leetcode.com/problems/product-of-array-except-self/">문제링크</a>
 */
fun productExceptSelf(nums: IntArray): IntArray {
    val result = IntArray(nums.size) { 0 }
    var tmp = 1
    for (i in nums.indices) {
        result[i] = tmp
        tmp *= nums[i]
    }
    tmp = 1
    for (i in nums.size - 1 downTo 0) {
        result[i] *= tmp
        tmp *= nums[i]
    }
    return result
}

fun main() {
    println(productExceptSelf(intArrayOf(1, 2, 3, 4)).contentToString())
}