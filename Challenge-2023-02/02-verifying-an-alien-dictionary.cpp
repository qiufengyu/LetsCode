#include "../header.h"

class Solution {
    string translate(unordered_map<char, char>& m, string& input) {
        for (int i = 0; i < input.size(); ++i) {
            input[i] = m[input[i]];
        }
        return input;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> m;
        char c = 'a';
        for (int i = 0; i < order.size(); ++i) {
            m[order[i]] = c;
            c++;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            string s1 = translate(m, words[i]), s2 = translate(m, words[i+1]);
            if (s1 > s2) {
                return false;
            }            
        }
        return true;
    }
};