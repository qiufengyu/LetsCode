#include "../header.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) {
            return false;
        }
        map<char, string> A2B;
        map<string, char> B2A;
        for (int i = 0; i < pattern.size(); i++) {
            A2B[pattern[i]] = words[i];
            B2A[words[i]] = pattern[i];
        }
        string _p, _str;
        for (int i = 0; i < pattern.size(); i++) {
            _p.push_back(B2A[words[i]]);
            _str += (A2B[pattern[i]] + " ");
        }
        _str.erase(_str.end() - 1);
        return _p.compare(pattern) == 0 && _str.compare(str) == 0;        
    }
};

int main() {
    string p {"abba"}, s {"dog dog dog dog"};
    cout << Solution().wordPattern(p, s) << endl;
    return 0;    
}