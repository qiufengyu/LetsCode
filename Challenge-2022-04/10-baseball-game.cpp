#include "../header.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (string& s: ops) {
            if (s == "+") {
                int s1 = v.back();
                v.pop_back();
                int s2 = v.back();
                v.push_back(s1);
                v.push_back(s1 + s2);
            } else if (s == "D") {
                int s1 = v.back();
                v.push_back(2 * s1);
            } else if (s == "C") {
                v.pop_back();
            } else {
                v.push_back(stoi(s));
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};