#include "../header.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vec(26, 1);
        for (auto c: sentence) {
            vec[c-'a'] = 0;
        }
        return accumulate(vec.begin(), vec.end(), 0) == 0;
    }
};