#include "../header.h"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] > b[1];
        });
        int res = 0, sum = 0, temp = 0;
        for (auto const& p: boxTypes) {
            temp = truckSize - p[0];
            if (temp >= 0) {
                res += p[0] * p[1];
                truckSize = temp;
            } else {
                res += p[1] * truckSize;
                break;
            }
        }
        return res;
    }
};