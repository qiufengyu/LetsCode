#include "../header.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> cm;
        int res = 0;
        for (int i = 0; i < chars.size(); i++) {
           cm[chars[i]]++;
        }
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            unordered_map<char, int> wm;
            int flag = 1;
            for (int j = 0; j < w.size(); j++) {
                wm[w[j]] ++;
            }
            for (auto const p: wm) {
                if (cm.count(p.first) == 0 || cm[p.first] < p.second) {
                    flag = 0;
                    break;
                }
            }
            res += (flag * w.size());
        }
        return res;
    }
};