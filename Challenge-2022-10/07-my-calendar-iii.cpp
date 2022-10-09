#include "../header.h"

class MyCalendarThree {
    map<int, int> count;
    int res;
public:
    MyCalendarThree(): res{0}, count{{-1, 0}} {
        
    }
    
    int book(int start, int end) {
        auto st = count.emplace(start, prev(count.upper_bound(start))->second);
        auto ed = count.emplace(end, prev(count.upper_bound(end))->second);
        for (auto it = st.first; it != ed.first; ++it) {
            ++(it->second);
            res = max(res, it->second);
        }
        return res;
    }
};

