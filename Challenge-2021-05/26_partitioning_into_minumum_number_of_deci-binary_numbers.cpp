#include "../header.h"

class Solution {
public:
    int minPartitions(string n) {
        char m = n[0];
        for (auto const& c: n) {
            if (c > m) {
              m = c;
            }
        }
        return m - '0';
    }
};