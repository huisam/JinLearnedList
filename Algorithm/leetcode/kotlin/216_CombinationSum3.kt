package com.huisam.kotlin.leetcode

fun combinationSum3(k: Int, n: Int): List<List<Int>> {
    val ans = mutableSetOf<Set<Int>>()
    fun recursive(now: MutableSet<Int>, start: Int, count: Int, goal: Int) {
        if (count == goal) {
            ans.add(now.toSet())
            return
        }

        (start..9).asSequence()
            .takeWhile { count + it <= goal }
            .filter { !now.contains(it) }
            .forEach {
                now.add(it)
                recursive(now, start + 1, count + it, goal)
                now.remove(it)
            }

    }
    recursive(mutableSetOf(), 1, 0, n)
    return ans.asSequence()
        .filter { it.size == k }
        .map { it.toList() }
        .toList()
}

fun main() {
    println(combinationSum3(3, 7))
}