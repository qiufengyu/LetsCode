#include "../header.h"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> lastIndexMap;
        for (int i = 0; i < s.size(); ++i) {
            lastIndexMap[s[i]] = i;
        }
        for (int i = 0; i < s.size(); ++i) {            
            int lastIndex = lastIndexMap[s[i]];
            for (int j = i + 1; j <= lastIndex; ++j) {
                if (lastIndex < lastIndexMap[s[j]]) {
                    lastIndex = lastIndexMap[s[j]];
                }
            }           
            res.push_back(lastIndex - i + 1);
            // no need to add one since for loop will do
            i = lastIndex;
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> res = Solution().partitionLabels(s);
    print_vector<int>(res);
    return 0;
}