#include "../header.h"

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> m;
        int d12 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int d13 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        int d14 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        int d23 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        int d24 = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);
        int d34 = (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);
        m[d12]++;
        m[d13]++;
        m[d14]++;
        m[d23]++;
        m[d24]++;
        m[d34]++;
        if (m.size() == 2) {
            bool flag1 = false;
            bool flag2 = false;
            for (auto& e: m) {
                if (e.second == 2) {
                    flag1 = true;
                } else if (e.second == 4) {
                    flag2 = true;
                }
            }
            return flag1 && flag2;
        }
        return false;
    }
};