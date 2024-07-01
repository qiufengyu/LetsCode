#include "../header.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (1 - grumpy[i]) * customers[i];
        }
        int tmp = 0;
        for (int i = 0; i < minutes; i++) {
            tmp += grumpy[i] * customers[i];
        }
        int res = sum + tmp;
        for (int i = minutes; i < n; i++) {
            tmp -= grumpy[i - minutes] * customers[i - minutes];
            tmp += grumpy[i] * customers[i];
            res = max(res, sum + tmp);
        }
        return res;
    }
};