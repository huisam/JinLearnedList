class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        dp = [[0] * m for i in range(n)]
        dp[n - 1][m - 1] = max(1 - dungeon[n - 1][m - 1], 1)

        for i in range(n - 2, -1, -1):
            dp[i][m - 1] = max(dp[i + 1][m - 1] - dungeon[i][m - 1], 1)

        for j in range(m - 2, -1, -1):
            dp[n - 1][j] = max(dp[n - 1][j + 1] - dungeon[n - 1][j], 1)

        for i in range(n - 2, -1, -1):
            for j in range(m - 2, -1, -1):
                down = max(dp[i + 1][j] - dungeon[i][j], 1)
                right = max(dp[i][j + 1] - dungeon[i][j], 1)
                dp[i][j] = min(down, right)
        return dp[0][0]