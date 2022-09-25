#include "../header.h"

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) {
            return {};
        }
        sort(changed.begin(), changed.end());
        vector<bool> doubled(changed.size(), false);
        vector<int> res;
        for (auto it = changed.begin(); it != changed.end(); ++it) {
            if (doubled[it - changed.begin()]) {
                continue;
            }
            int dint = (*it) * 2;
            auto dit = lower_bound(it + 1, changed.end(), dint);
            while (dit != changed.end() && doubled[dit-changed.begin()]) {
                ++dit;
            }
            if (dit == changed.end() || dint != *dit) {
                return {};
            } else {
                res.push_back(*it);
                doubled[dit-changed.begin()] = true;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> changed = stringToIntegerVector(s);
    vector<int> res = Solution().findOriginalArray(changed);
    print_vector<int>(res);
    return 0;
}