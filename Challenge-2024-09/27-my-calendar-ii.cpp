#include "../header.h"

class MyCalendarTwo {
    map<int, int> records;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        records[start]++;
        records[end]--;
        int count = 0;
        for (auto const& r: records) {
            count += r.second;
            if (count >= 3) {
                records[start]--;
                records[end]++;
                return false;
            }
        }
        return true;
    }
};