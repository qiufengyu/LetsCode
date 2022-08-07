#include "../header.h"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double t = 1.0 + minutesToTest / minutesToDie;
        return ceil(log(double(buckets)) / log(t));
    }
};