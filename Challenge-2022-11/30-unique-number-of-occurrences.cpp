#include "../header.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        unordered_set<int> st;
        for (int i = 0; i < arr.size(); ++i) {
            ++count[arr[i]];
        }
        for (auto const& p: count) {
            if (st.count(p.second)) {
                return false;
            } else {
                st.insert(p.second);
            }
        }
        return true;
    }
};