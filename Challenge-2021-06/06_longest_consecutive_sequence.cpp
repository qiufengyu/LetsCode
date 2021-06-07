#include "../header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());
        int longest = 0;
        for (auto const& num: nset) {
          if (!nset.count(num-1)) {
            int currentNum = num;
            int currentLength = 1;
            while (nset.count(currentNum + 1)) {
              ++currentNum;
              ++currentLength;
            }
            longest = max(longest, currentLength);
          }
        }
        return longest;        
    }
};