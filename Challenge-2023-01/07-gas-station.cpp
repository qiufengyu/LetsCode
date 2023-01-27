#include "../header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, current = 0;
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            current += (gas[i] - cost[i]);
            if (current < 0) {
                res = i + 1;
                current = 0;
            }
        }
        if (totalGas < totalCost) {
            return -1;
        }
        return res;
    }
};