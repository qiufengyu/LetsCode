#include "../header.h"

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res (num_people, 0);
        int rounds = int((sqrt(1 + 8.0 * (double) candies) - 1 ) / 2);
        int idx = min(num_people, rounds);
        int left = candies - rounds * (rounds + 1) / 2;
        for (int i = 1; i <= idx; i++) {
            int n = (rounds - i) / num_people + 1;
            res[i-1] = n * i + n * (n - 1) / 2 * num_people;
        }
        if (left > 0) {
            int remain = rounds % num_people;
            res[remain] += left;
        }
        return res;
        
    }
};

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> v = Solution().distributeCandies(c, n);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}