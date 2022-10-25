#include "../header.h"

struct wc {
    string word;
    int count;
    wc(string w, int c): word{w}, count{c} {}
    friend bool operator< (wc const& a, wc const& b);
};

bool operator< (wc const& a, wc const& b) {
    if (a.count == b.count) {
        return a.word < b.word;
    }
    return a.count > b.count;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<wc> vec;
        vector<string> res;
        for (auto const& w: words) {
            ++m[w];
        }
        for (auto const& p: m) {
            wc x = wc(p.first, p.second);
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < k; ++i) {
            res.push_back(vec[i].word);
        }
        return res;
    }
};