#include "../header.h"

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> bits;
        bits[0] = 1;
        long long result = 0LL;
        int bitmask = 0;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            bitmask ^= (1 << idx);
            // all even occurance
            result += bits[bitmask];
            for (int j = 0; j < 10; j++) {
                result += bits[bitmask ^ (1 << j)];
            }
            bits[bitmask]++;
        }
        return result;
    }
};