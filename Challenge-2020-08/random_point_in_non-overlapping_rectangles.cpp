#include "../header.h"

class Solution {
public:
    Solution(vector<vector<int>>& rects): _rects{rects}, sum{0} {        
        for (int i = 0; i < rects.size(); i++) {
            vector<int> v = rects[i];
            sum += (v[2] - v[0] + 1) * (v[3] - v[1] + 1);
            area.push_back(sum);
        }
        cout << "AREA: ";
        for (auto x: area) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    vector<int> pick() {
        int randIndex = rand() % sum + 1;
        auto it = lower_bound(area.begin(), area.end(), randIndex);
        cout << "randIndex: " << randIndex << endl;
        int diff = it - area.begin();
        cout << "diff: " << diff << endl;
        int res = *it - randIndex;
        cout << "res: " << res << endl;
        int x = _rects[diff][2] - _rects[diff][0] + 1;
        int resY = _rects[diff][1] + res / x;
        int resX = _rects[diff][0] + res % x;
        return {resX, resY};
    }
private:
    vector<vector<int>> _rects;
    vector<int> area;
    int sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main() {
    vector<int> r1 {-2, -2, -1, -1};
    vector<int> r2 {1, 0, 3, 0};
    vector<vector<int>> rects {r1, r2};
    Solution *obj = new Solution(rects);
    for (int i = 0; i < 20; i++) {
        auto r = obj->pick();
        cout << "[" << r[0] << ", " << r[1] << "]" << endl;
    }
    return 0;
}