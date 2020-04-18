class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ans = [0 for i in range(len(T))]
        stack = []
        for idx,t in enumerate(T):
            while stack and stack[-1][0] < t:
                temparature, index = stack.pop()
                ans[index] = idx - index
            stack.append((t,idx))
        return ans