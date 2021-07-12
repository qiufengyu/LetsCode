#include "../header.h"

class MedianFinder {
    multiset<int> _data;
    multiset<int>::iterator low, high;
public:
    /** initialize your data structure here. */
    MedianFinder(): low(_data.end()), high(_data.end()) {
        
    }
    
    void addNum(int num) {
        int sz = _data.size();
        _data.insert(num);
        if (sz == 0) {
            low = _data.begin();
            high = _data.begin();
        } else if (sz % 2 == 0) {
            // low + 1 == high
            if (num > *low && num < *high) {
                low++;
                high--;
            } else if (num <= *low) {
                high--;
                low = high;
            } else {
                low++;
            }
        } else {
            // low == high
            if (num < *low) {
                low--;
            } else {
                high++;
            }
        }        
    }
    
    double findMedian() {
        return (*low + *high) * 0.5;
        
    }
};
