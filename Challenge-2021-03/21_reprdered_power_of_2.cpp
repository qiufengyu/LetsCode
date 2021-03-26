#include "../header.h"

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> s;
        for (int i = 0; i < 31; i++) {
            string temp = to_string(1 << i);
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        string t = to_string(N);
        sort(t.begin(), t.end());
        return s.count(t) == 1;
    }
};