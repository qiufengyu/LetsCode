#include "../header.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            res += min(duration, timeSeries[i] - timeSeries[i-1]);
        }
        return res + duration;
    }
};

int main() {

}