from collections import defaultdict


class Node(object):
    def __init__(self) -> None:
        self.next = defaultdict(Node)
        self.count = defaultdict(int)


class Trie(object):
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        cur = self.root
        for w in word:
            cur.count[len(word)] += 1
            cur = cur.next[w]

    def find(self, word):
        cur = self.root
        for w in word:
            if w == "?":
                return cur.count[len(word)]
            else:
                cur = cur.next[w]


def solution(words, queries):
    answer = []
    prefix_trie = Trie()
    postfix_trie = Trie()
    for word in words:
        prefix_trie.insert(word)
        postfix_trie.insert(word[::-1])

    for query in queries:
        if query[0] == "?":
            answer.append(postfix_trie.find(query[::-1]))
        else:
            answer.append(prefix_trie.find(query))
    return answer