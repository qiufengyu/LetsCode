#include "../header.h"

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string current = "";
        vector<vector<string>> res;
        int count = 0;
        for (int i = 0; i < searchWord.size(); ++i) {
            current += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), current);
            count = 0;
            vector<string> v;
            while (count < 3 && it + count != products.end()) {
                string temp = *(it + count);
                // string.rfind(prefix, 0): it means starts with
                if (temp.rfind(current, 0) == 0) {
                    v.push_back(temp);
                } else {
                    break;
                }
                ++count;
            }
            res.push_back(v);
        }
        return res;
    }
};