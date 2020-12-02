#include "../header.h"

struct Event {
    int x;
    int h;
    int type;

    bool operator<(const Event& e) const {
        if (x == e.x) {
            return type * h > e.type * e.h;
        }
        return x < e.x;
    }
};

class Solution {
private:
    multiset<int> ms;
    int maxHeight() const {
        if (ms.empty()) {
            return 0;
        } else {
            return *ms.rbegin();
        }
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> events;
        vector<vector<int>> res;
        ms.clear();
        for (auto& b: buildings) {
            events.push_back(Event{b[0], b[2], 1});
            events.push_back(Event{b[1], b[2], -1});
        }
        sort(events.begin(), events.end());
        for (auto& e: events) {
            if (e.type > 0) {
                if (e.h > maxHeight()) {
                    res.push_back({e.x, e.h});
                }
                ms.insert(e.h);
            } else {
                ms.erase(ms.equal_range(e.h).first);
                if (e.h > maxHeight()) {
                    res.push_back({e.x, maxHeight()});
                }
            }
        }
        return res;
    }
};