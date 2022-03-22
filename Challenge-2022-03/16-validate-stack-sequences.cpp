#include "../header.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushIndex = 0, popIndex = 0;
        while (pushIndex < pushed.size() || popIndex < popped.size()) {
            if (popIndex < popped.size() && !s.empty() && s.top() == popped[popIndex]) {
                s.pop();
                ++popIndex;
            }
            else if (pushIndex < pushed.size()) {
                s.push(pushed[pushIndex]);
                ++pushIndex;
            } else {
                return false;
            }
        }
        return s.empty();
    }
};
