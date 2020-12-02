#include "../header.h"

class HelperQueue {
private:
    deque<int> _q;
public:
    void push(int x) {
        while(!_q.empty() && x > _q.back()) {
            _q.pop_back();
        }
        _q.push_back(x);
    }

    void pop() {
        _q.pop_front();
    }

    int max() const {
        return _q.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        HelperQueue hq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            hq.push(nums[i]);
            if (i - k + 1 >= 0) {
                ans.push_back(hq.max());
                if (nums[i - k + 1] == hq.max()) {
                    hq.pop();
                }
            }
        }
        return ans;
    }
};
