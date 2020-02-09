class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0:
            return []
        if k == 1:
            return nums
        else:
            import heapq
            ans, q = [], []
            for i in range(k):
                heapq.heappush(q, (-nums[i], i))
            ans.append(-q[0][0])
            
            for i in range(k, len(nums)):
                while q[0][1] <= i - k:
                    heapq.heappop(q)
                heapq.heappush(q, (-nums[i], i))
                ans.append(-q[0][0])
            return ans