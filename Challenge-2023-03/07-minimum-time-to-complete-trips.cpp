#include "../header.h"

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = (long long)time[0] * totalTrips;
        long long m = l + (r - l) / 2;
        while (l < r) {
            m = l + (r - l) / 2;
            if (fit(time, m, totalTrips)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    bool fit(vector<int>& time, long long t, long long totalTrips) {
        long long trips = 0;
        for (auto const& tm: time) {
            trips += t / tm;
        }
        return trips >= totalTrips;
    }
};

int main() {
    vector<int> time {2};
    int totalTrips = 1;
    cout << Solution().minimumTime(time, totalTrips) << endl;
    return 0;
}