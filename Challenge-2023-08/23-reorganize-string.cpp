#include "../header.h"

typedef pair<int, char> PIC;

class Solution {
public:
    string reorganizeString(string s) {
        string res = " ";
        unordered_map<char, int> m;
        for (auto const c: s) {
            m[c]++;
        }
        priority_queue<PIC, vector<PIC>> pq;
        for (auto const& p: m) {
            pq.emplace(p.second, p.first);
        }
        while (!pq.empty()) {
            auto tp1 = pq.top();
            pq.pop();
            if (pq.empty()) {
                if (tp1.first > 1) {
                    return "";
                } else {
                    res.push_back(tp1.second);
                    return res.substr(1);
                }
            } else {
                auto tp2 = pq.top();
                pq.pop();
                // cout << "res = " << res << ", tp1 char = " << tp1.second << ", tp2 char = " << tp2.second << endl;
                if (tp1.second == res.back()) {
                    res.push_back(tp2.second);
                    tp2.first--;
                    if (tp2.first > 0) {
                        pq.push(tp2);
                    }
                    pq.push(tp1);
                } else {
                    res.push_back(tp1.second);
                    tp1.first--;
                    if (tp1.first > 0) {
                        pq.push(tp1);
                    }
                    pq.push(tp2);
                }
            }            
        }
        return res.substr(1);
    }
};

int main() {
    string s{"aaaabbbbcccdee"};
    cout << Solution().reorganizeString(s) << endl;
    return 0;
}