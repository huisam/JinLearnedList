class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        def go(idx, numbers, count):
            if count == target:
                ans.append(numbers)
                return
            
            for i in range(idx, len(candidates)):
                if count + candidates[i] > target:
                    break
                else:
                    go(i, numbers + [candidates[i]], count + candidates[i])
        go(0, [], 0)
        return ans