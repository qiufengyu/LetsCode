#include "../header.h"

struct Height {
    int x;
    int h;
    int type;

    bool operator<(const Height& oh) const {
        if (x == oh.x) {
            return type * h > oh.type * oh.h;
        }
        return x < oh.x;
    }
};

class Solution {
    multiset<int> ms;
    int maxHeight() const {
        return ms.empty() ? 0 : *ms.rbegin();
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<Height> height;
        for (vector<int>& b: buildings) {
            height.push_back(Height{b[0], b[2], 1});
            height.push_back(Height{b[1], b[2], -1});
        }
        sort(height.begin(), height.end());
        for (auto& h: height) {
            if (h.type > 0) {
                if (h.h > maxHeight()) {
                    res.push_back({h.x, h.h});
                }
                ms.insert(h.h);
            } else {
                ms.erase(ms.equal_range(h.h).first);
                if (h.h > maxHeight()) {
                    res.push_back({h.x, maxHeight()});
                }
            }
        }
        return res;
    }
};