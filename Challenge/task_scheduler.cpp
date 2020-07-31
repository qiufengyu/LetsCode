#include "../header.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t (26, 0);
        for (auto x: tasks) {
            t[x - 'A'] += 1;
        }
        int maxCount = *max_element(t.begin(), t.end());
        int ans = (maxCount - 1) * (n + 1);
        // last group, not only the task occurs max times
        for (auto y: t) {
            if (y == maxCount) {
                ans++;
            }
        }
        return max((int)tasks.size(), ans);
    }
};

int main() {

}