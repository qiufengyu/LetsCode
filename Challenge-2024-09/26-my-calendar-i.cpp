#include "../header.h"

class MyCalendar {
    vector<pair<int, int>> slots;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (slots.size() == 0) {
            slots.push_back({start, end});
            return true;
        }
        int i = 0;
        while (i < slots.size()) {
            if (slots[i].first < start) {
                i++;
            } else {
                break;
            }
        }
        if (i == 0) {
            if (slots[0].first >= end) {
                slots.insert(slots.begin(), {start, end});
                return true;
            } else if (slots.size() > 1 && slots[i].second <= start && slots[i+1].first >= end) {
                slots.insert(slots.begin() + 1, {start, end});
                return true;
            } else {
                return false;
            }
        } else if (i == slots.size()) {
            if (slots.back().second <= start) {
                slots.push_back({start, end});
                return true;
            } else {
                return false;
            }
        } else {
            if (slots[i-1].second <= start && slots[i].first >= end) {
                slots.insert(slots.begin() + i, {start, end});
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};