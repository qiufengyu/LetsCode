#include "../header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0, tank = 0, sz = gas.size();
        for (int i = 0; i < sz * 2; ++i) {
            tank += (gas[i % sz] - cost[i % sz]);
            if (tank < 0) {
                tank = 0;
                if (i >= sz) {
                    return -1;
                } else {
                    index = (i + 1) % sz;
                }
            }
        }
        if (index == sz - 1) {
            int _t = gas[sz - 1] - cost[sz - 1];
            if (_t < 0) {
                return -1;
            }
            for (int i = 0; i < sz - 1; ++i) {
                _t += (gas[i] - cost[i]);
                if (_t < 0) {
                    return -1;
                }
            }
            return sz - 1;
        }
        return index;
    }
};

int main() {
    string g, c;
    cin >> g >> c;
    vector<int> gas = stringToIntegerVector(g), cost = stringToIntegerVector(c);
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}