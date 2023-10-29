#include "../header.h"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int b = minutesToTest / minutesToDie + 1;
        return ceil(log2(buckets) / log2(b));
    }
};