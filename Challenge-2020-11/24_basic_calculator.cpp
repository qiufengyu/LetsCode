#include "../header.h"

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        stack<int> nums;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    nums.push(num);
                } else if (op == '-') {
                    nums.push(-num);
                } else {
                    int temp;
                    if (op == '*') {
                        temp = nums.top() * num;
                    } else {
                        temp = nums.top() / num;
                    }
                    nums.pop();
                    nums.push(temp);
                }                
                num = 0;
                op = c;
            }
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};