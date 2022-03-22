class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st = []
        res = []
        for i in range(len(s)):
            res.append(s[i])
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                if len(st) == 0:
                    res[i] = ''
                else:
                    st.pop()
        while len(st) > 0:
            res[st.pop()] = ''            
        return ''.join(res)

if __name__ == '__main__':
    solution = Solution()
    print(solution.minRemoveToMakeValid('))(('))