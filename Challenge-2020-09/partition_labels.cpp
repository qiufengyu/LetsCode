#include "../header.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> m;
        for (char c = 'a'; c <= 'z'; c++) {
            m[c] = -1;
        }
        for (int i = 0; i < S.length(); i++) {
            m[S[i]] = i;
        }
        vector<int> v;
        int start = 0, end = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, m[S[i]]);
            if (i == end) {
                v.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return v;
    }
};