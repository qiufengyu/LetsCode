#include "../header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        unordered_set<int> st;
        int x = 1;
        for (int i = 1; i <= 31; i++) {
            st.insert(x);
            x <<= 1;
        }
        return st.count(n) != 0;
    }
};