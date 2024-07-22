#include "../header.h"

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int b = numBottles;
        while (b >= numExchange) {
            res += b / numExchange;
            b = b / numExchange + b % numExchange;
        }
        return res;
    }
};