#include "../header.h"

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size() / 2;
        unordered_set<int> s(candyType.begin(), candyType.end());
        return n < s.size() ? n : s.size();
    }
};