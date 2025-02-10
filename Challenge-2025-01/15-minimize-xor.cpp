#include "../header.h"

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = __builtin_popcount(num1), n2 = __builtin_popcount(num2);
        if (n1 != n2) {
            queue<int> q1;
            vector<int> q2;
            for (int i = 0; i < 32; i++) {
                int test = (1U << (31 - i));
                if ((test & num1) != 0) {
                    q1.push(i);
                } else {
                    q2.push_back(i);
                }
            }
            if (n2 < n1) {
                int res = 0;
                while (n2) {
                    res = res | (1U << (31 - q1.front()));
                    q1.pop();
                    n2--;
                }
                return res;
            } else {
                int res = num1, count = n2 - n1;
                reverse(q2.begin(), q2.end());
                while (count) {
                    res = res | (1U << (31 - q2[n2 - n1 - count]));
                    count--;
                }
                return res;
            }
        }
        return num1;
    }
};

int main() {
    int num1 = 25, num2 = 72;
    cout << Solution().minimizeXor(num1, num2) << endl;
    return 0;
}