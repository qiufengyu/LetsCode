#include "../header.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            if (people[r] + people[l] <= limit) {
                ++res;
                r--;
                l++;
            } else {
                ++res;
                r--;
            }
        }
        return res + (l == r);
    }
};