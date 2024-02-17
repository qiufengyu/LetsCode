#include "../header.h"

class SummaryRanges {
    set<int> nums;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start = *nums.begin(), end = *nums.begin();
        for (auto it = (++nums.begin()); it != nums.end(); ++it) {
            int val = *it;
            if (val - end == 1) {
                end = val;
            } else {
                res.push_back({start, end});
                start = val;
                end = val;
            }
        }
        res.push_back({start, end});
        return res;        
    }
};