#include "../header.h"

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int> maskCount;
        for (const string& w: words) {
            int mask = 0;
            for (const char& c: w) {
                mask |= 1 << (c - 'a');
            }
            ++maskCount[mask];
        }
        for (const string& p: puzzles) {
            int mask = 0;
            for (const char& c: p) {
                mask |= 1 << (c - 'a');
            }
            int sub = mask, count = 0, first = 1 << (p[0] - 'a');
            while (true) {
                if ((sub & first) == first && maskCount.count(sub)) {
                    count += maskCount[sub];
                }
                if (sub == 0) {
                    break;
                }
                sub = (sub - 1) & mask;
            }
            res.push_back(count);
        }
        return res;
    }
};