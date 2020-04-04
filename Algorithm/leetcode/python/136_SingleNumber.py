from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res ^= num
        return res


print(Solution().singleNumber([2,2,1]))
