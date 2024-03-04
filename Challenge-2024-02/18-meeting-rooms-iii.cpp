#include "../header.h"

typedef long long LL;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);
        vector<LL> times(n, 0LL);
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0], end = meetings[i][1];
            long long minTime = LLONG_MAX;
            bool found = false;
            int minIndex = -1;
            for (int j = 0; j < n; j++) {
                if (times[j] <= start) {
                    found = true;
                    count[j]++;
                    times[j] = end;
                    break;
                }
                if (minTime > times[j]) {
                    minTime = times[j];
                    minIndex = j;
                }
            }
            if (!found) {
                times[minIndex] += (end - start);
                count[minIndex]++;
            }
        }
        int maxCount = 0, maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};