class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        for i in range(len(s)):
            if s[i] == goal[0]:
                if (s[i:] + s[0:i]) == goal:
                    return True                
        return False