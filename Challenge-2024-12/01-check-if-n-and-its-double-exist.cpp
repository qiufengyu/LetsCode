#include "../header.h"

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (int i = 0; i < arr.size(); i++) {
            if (st.count(arr[i] * 2 )) {
                return true;
            } else if (arr[i] % 2 == 0 && st.count(arr[i] / 2) != 0) {
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};