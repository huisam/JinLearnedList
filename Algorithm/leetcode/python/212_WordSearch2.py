import collections


class Node(object):
    def __init__(self) -> None:
        self.next = collections.defaultdict(Node)
        self.end = False


class Trie(object):
    def __init__(self) -> None:
        self.root = Node()

    def set_name_trie(self, word):
        now = self.root
        for i in range(len(word)):
            now = now.next[word[i]]
        now.end = True

    def find_name_trie(self, word):
        now = self.root
        for i in range(len(word)):
            if word[i] not in now.next:
                return False
            now = now.next[word[i]]
        return now.end


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie, db = Trie(), set(words)
        n, m = len(board), len(board[0])
        dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
        ans = []

        def dfs(x, y, visit, word, node):
            if not node:
                return

            if node.end:
                ans.append(word)
                node.end = False

            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= m or ny < 0 or ny >= n or visit[ny][nx]:
                    continue
                visit[ny][nx] = True
                dfs(nx, ny, visit, word + board[ny][nx], node.next.get(board[ny][nx]))
                visit[ny][nx] = False

        for word in words:
            trie.set_name_trie(word)

        for i in range(n):
            for j in range(m):
                word = board[i][j]
                visit = [[False] * m for i in range(n)]
                visit[i][j] = True
                dfs(j, i, visit, word, trie.root.next.get(board[i][j]))
        return ans