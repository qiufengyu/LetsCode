#include "../header.h"

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.size();
        int i = 0;
        for (i = l - 1; i > 0; i--) {
          if (s[i] > s[i - 1]) break;
        }
        if (i == 0) {
          return -1;
        }
        for (int j = l - 1; j >= i; j--) {
          if (s[j] > s[i-1]) {
            swap(s[j], s[i-1]);
            break;
          }
        }
        sort(s.begin() + i, s.end());
        long long r = stoll(s);
        return r > INT_MAX ? -1 : r;
    }
};