#include "../header.h"

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
          for (int j = 0; j <= words[i].size(); ++j) {
            for (int k = 0; k <= words[i].size(); ++k) {
              m[words[i].substr(0, j) + "#" + words[i].substr(words[i].size() - k)] = i;
            }
          }
        }
    }
    
    int f(string prefix, string suffix) {
      return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;        
    }
private:
  unordered_map<string, int> m;
};
