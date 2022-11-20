#include "../header.h"

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int s = 1;
        while (!st.empty() && price >= st.top().first) {
            s += st.top().second;
            st.pop();
        }
        st.push({price, s});
        return s;
        
    }
};