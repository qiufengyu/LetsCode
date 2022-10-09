#include "../header.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> m(26, -1);
        for (string& equation: equations) {
            char l = equation[0], op = equation[1], r = equation[3];
            int li = l - 'a', ri = r - 'a';
            if (op == '=') {
                if (l != r) {
                    u(li, ri, m);
                }
            }
        }
        for (string& equation: equations) {
            char l = equation[0], op = equation[1], r = equation[3];
            int li = l - 'a', ri = r - 'a';
            if (op == '!') {
                if (l == r) {
                    return false;
                } else {
                    int fl = f(li, m), fr = f(ri, m);
                    if (fl == fr) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void u(int a, int b, vector<int>& m) {
        int af = f(a, m);
        int bf = f(b, m);
        if (af != m[bf]) {
            m[bf] = af;
        }        
    }

    int f(int a, vector<int>& m) {
        if (m[a] == -1) {
            m[a] = a;
            return a;
        }
        if (m[a] == a) {
            return a;
        }
        return f(m[a], m);
    }
};