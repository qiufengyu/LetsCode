#include "../header.h"

class Solution {
public:
    long long minEnd(int n, int x) {
        deque<int> dq;
        int xx = x, index = 0;
        while (xx) {
            if ((xx & 1) == 0) {
                dq.push_back(index);
            }
            index++;
            xx = (xx >> 1);
        }
        unsigned int add = 0;
        long long nn = n;
        long long right = (1LL << dq.size());
        long long left = nn / right + (nn % right == 0 ? -1 : 0);
        left = (left << index);
        left = max(left, 0LL);
        nn =  (nn - 1) % right;
        while (nn) {
            if ((nn & 1) == 1) {
                int t = dq.front();
                add = add | (1 << t);
            }
            dq.pop_front();
            nn = (nn >> 1);
        }
        return (long long)left + (long long) x + (long long)add;
    }
};

int main() {
    int n = 4, x = 2;
    cout << Solution().minEnd(n, x) << endl;
    return 0;
}