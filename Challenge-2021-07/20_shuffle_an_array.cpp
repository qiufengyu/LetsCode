#include "../header.h"

class Solution {
private:
    vector<int> _v;
public:
    Solution(vector<int>& nums): _v(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = _v;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;        
    }
};
