#include "../header.h"

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto const &a: arr) {
            ++m[a];
        }
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<int, int> const & a, pair<int, int> const & b) -> bool {
            return a.second > b.second;
        });
        int sz = arr.size() / 2;
        int s = 0, res = 0;
        for (auto const &p: v) {
            s += p.second;
            ++res;
            if (s >= sz) {
                return res;
            }
        }   
        return res;
    }
};

int main() {
    vector<int> v {3,3,3,3,5,5,5,2,2,7};
    cout << Solution().minSetSize(v) << endl;
    return 0;
}