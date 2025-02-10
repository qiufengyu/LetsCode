#include "../header.h"

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> t(n, 0);
        for (int i = 1; i < n; i++) {
            t[i] = t[i-1] ^ derived[i-1];
        }
        if ((derived.back() ^ t.back()) == 0) {
            return true;
        }
        t[0] = 1;
        for (int i = 1; i < n; i++) {
            t[i] = t[i-1] ^ derived[i-1];
        }
        return (derived.back() ^ t.back()) == 1;
    }
};