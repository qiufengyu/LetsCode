#include "../header.h"

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target++;
            }
            ++res;
        }
        return res + (startValue - target);
    }
};

int main() {
    int start, target;
    cin >> start >> target;
    cout << Solution().brokenCalc(start, target) << endl;
    return 0;
}