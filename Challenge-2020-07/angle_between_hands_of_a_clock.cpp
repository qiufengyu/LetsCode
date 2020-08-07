#include "header.h"

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ma = minutes * 6.0;
        double ha = hour * 30.0 + minutes * 0.5;
        double a = abs(ma - ha);
        return min(a, 360 - a);
    }
};

int main() {
    int hour, minutes;
    cin >> hour >> minutes;
    cout << Solution().angleClock(hour, minutes) << endl;
    return 0;
}