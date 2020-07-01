#include "header.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int> &a, const vector<int>& b) {
            if (a[0] > b[0]) return true;
            else if (a[0] == b[0]) return a[1] < b[1];
            return false;
        };
        sort(people.begin(), people.end(), cmp);
        print_vector(people);
        vector<vector<int>> res;
        for (auto &p: people) {
            res.insert(res.begin() + p[1], p);
            print_vector(res);
        }
        return res;
    }
};

int main() {
   vector<vector<int>> v {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
   vector<vector<int>> res = Solution().reconstructQueue(v);
   print_vector(res);
   return 0;
}