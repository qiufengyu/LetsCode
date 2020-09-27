#include "../header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxGasIndex = max_element(gas.begin(), gas.end()) - gas.begin();
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] >= cost[i]) {
                int g = 0;
                bool flag = true;
                for (int j = i; j < gas.size(); j++) {
                    g += gas[j];
                    g -= cost[j];
                    if (g < 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int j = 0;  j < i; j++) {
                        g += gas[j];
                        g -= cost[j];
                        if (g < 0) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    string sg, sc;
    cin >> sg >> sc;
    vector<int> gas = stringToIntegerVector(sg);
    vector<int> cost = stringToIntegerVector(sc);
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}