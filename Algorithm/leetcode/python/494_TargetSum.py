class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        from collections import defaultdict
        d = defaultdict(int)
        d[1000 - nums[0]] += 1
        d[1000 + nums[0]] += 1

        for i in range(1, len(nums)):
            n = defaultdict(int)
            for j in d.keys():
                n[j - nums[i]] += d[j]
                n[j + nums[i]] += d[j]
            d = n
        return d[1000 + S] if not S > 1000 else 0