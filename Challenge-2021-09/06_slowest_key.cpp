#include "../header.h"

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.size();
        int cMax = releaseTimes[0];
        char res = keysPressed[0];
        int temp = 0;
        for (int i = 1; i < n; ++i) {
            temp = releaseTimes[i] - releaseTimes[i-1];
            if (temp > cMax) {
                cMax = temp;
                res = keysPressed[i];
            } else if (temp == cMax) {
                res = max(res, keysPressed[i]);
            }
        }
        return res;
    }
};