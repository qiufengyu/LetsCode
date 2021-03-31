#include "../header.h"

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> count;
        for (char c: s) {
          ++count[c];
        }
        int nums[10];
        memset(nums, 0, sizeof(nums));
        nums[0] = count['z'];
        nums[2] = count['w'];
        nums[4] = count['u'];
        nums[6] = count['x'];
        nums[8] = count['g'];
        nums[3] = count['h'] - nums[8];
        nums[5] = count['f'] - nums[4];
        nums[7] = count['s'] - nums[6];
        nums[1] = count['o'] - nums[0] - nums[2] - nums[4];
        nums[9] = (count['n'] - nums[1] - nums[7]) / 2;
        string res;
        for (int i = 0; i < 10; ++i) {
          for (int j = 0; j < nums[i]; ++j) {
            res += ('0' + i);
          }
        }
        return res;
    }
};