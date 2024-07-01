#include "../header.h"

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = (position[n-1] - position[0]) / (m - 1), res = 0;
        while (l <= r) {
            int x = l + (r - l) / 2;
            auto p = test(position, x, n);
            if (p.first >= m) {
                l = x + 1;
                res = max(res, p.second);
            } else {
                r = x - 1;
            }
        }
        return res;
    }

    pair<int, int> test(vector<int>& position, int force, const int n) {
        int count = 1, start = position[0], minValue = position[n-1] - position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - start >= force) {
                count++;
                minValue = min(minValue, position[i] - start);
                start = position[i];                
            }
        }
        return {count, minValue};
    }
};

int main() {
    vector<int> position{1,2,3,4,5,6,7,8,9,10};
    int m = 4;
    cout << Solution().maxDistance(position, m) << endl;
    return 0;
}