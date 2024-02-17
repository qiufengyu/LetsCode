#include "../header.h"

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }
        while (!q.empty()) {
            int sz = q.size();
            while (sz) {
                int frt = q.front();
                q.pop();
                if (frt >= low && frt <= high) {
                    res.push_back(frt);
                }
                // generate next number
                if (frt <= high) {                    
                    int last = frt % 10;
                    if (last < 9) {
                        q.push(frt * 10 + last + 1);
                    }
                }
                sz--;
            }
        }
        return res;
    }
};

int main() {
    int low = 1000, high = 13000;
    auto res = Solution().sequentialDigits(low, high);
    print_vector<int>(res);
    return 0;
}