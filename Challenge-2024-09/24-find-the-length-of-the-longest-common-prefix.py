from typing import List


class TrieNode:
    def __init__(self):
        self.child = [None] * 10

def insert_key(root: TrieNode, key):
    curr = root
    for c in key:
        index = ord(c) - ord('0')
        if curr.child[index] is None:
            new_node = TrieNode()
            curr.child[index] = new_node
        curr = curr.child[index]

def search_key(root: TrieNode, key) -> int:
    curr = root
    length = 0
    for c in key:
        index = ord(c) - ord('0')
        if curr.child[index] is None:
            return length
        else:
            length += 1
        curr = curr.child[index]
    return length


class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        root = TrieNode()
        res = 0
        for x in arr1:
            insert_key(root, str(x))
        for y in arr2:
            res = max(res, search_key(root, str(y)))
        return res
