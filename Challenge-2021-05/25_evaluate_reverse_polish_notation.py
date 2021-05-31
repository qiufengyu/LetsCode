from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for token in tokens:
            if token == '+':
                a, b = st[-2], st[-1]
                st.pop()
                st.pop()
                c = a + b
                st.append(c)
            elif token == '-':
                a, b = st[-2], st[-1]
                st.pop()
                st.pop()
                c = a - b
                st.append(c)
            elif token == '*':
                a, b = st[-2], st[-1]
                st.pop()
                st.pop()
                c = a * b
                st.append(c)
            elif token == '/':
                a, b = st[-2], st[-1]
                st.pop()
                st.pop()
                c = int(a / b)
                st.append(c)
            else:
              st.append(int(token))
        return st[0]

if __name__ == '__main__':
    s = Solution()
    print(s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))
