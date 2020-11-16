#include "../header.h"

// How many states can we generate with x pigs and T tests?
// Find minimum x such that (T+1)^x >= N

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(T));
    }
};