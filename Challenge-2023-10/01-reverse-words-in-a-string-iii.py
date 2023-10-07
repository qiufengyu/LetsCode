class Solution:
    def reverseWords(self, s: str) -> str:
        parts = [w[::-1] for w in s.split(' ')]
        return ' '.join(parts)