from typing import List


class TrieNode:
    def __init__(self):
        self.child = [None] * 26
        self.count = 0

def insert_key(root: TrieNode, key):
    curr = root
    for c in key:
        index = ord(c) - ord('a')
        if curr.child[index] is None:
            new_node = TrieNode()
            curr.child[index] = new_node
        curr = curr.child[index]
        curr.count += 1

def search_key(root: TrieNode, key) -> int:
    curr = root
    count = 0
    for c in key:
        index = ord(c) - ord('a')        
        count += curr.child[index].count
        curr = curr.child[index]
    return count

def printTrie(root: TrieNode, index=-1, level=0):
    if root:
        print(' ' * level + chr(ord('a') + index) + ' : ' + str(root.count))
        for i in range(26):
            printTrie(root.child[i], i, level=level + 2)


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = TrieNode()
        for word in words:
            insert_key(root, word)
        printTrie(root, -1, 0)
        res = [0] * len(words)
        for i in range(len(words)):
            res[i] = search_key(root, words[i])
        return res
    
if __name__ == '__main__':
    words = ["abc","ab","bc","b"]
    print(Solution().sumPrefixScores(words))
