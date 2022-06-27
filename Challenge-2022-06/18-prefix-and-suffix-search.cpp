#include "../header.h"

class WordFilter {
    unordered_map<string, int> m;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (int j = 0; j <= words[i].size(); ++j) {
                string p = word.substr(0, j);
                for (int k = 0; k < words[i].size(); ++k) {
                    string s = word.substr(k, word.size());
                    m[p + "|" + s] = i;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        return m.count(prefix + "|" + suffix) ? m[prefix + "|" + suffix] : -1;        
    }
};