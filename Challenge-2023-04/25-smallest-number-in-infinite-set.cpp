#include "../header.h"

class SmallestInfiniteSet {
    int start;
    set<int> st;
public:
    SmallestInfiniteSet(): start{1} {
        
    }
    
    int popSmallest() {
        if (!st.empty()) {
            int res = *st.begin();
            if (res <= start) {
                st.erase(res);
                if (res == start) {
                    ++start;
                }
                return res;
            }
        }
        start++;
        return start - 1;        
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};