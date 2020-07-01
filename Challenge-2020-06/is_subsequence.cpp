#include "header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // or dp
        // length of longest common subsequence of s and t == s.length();
        int sSize = s.length(), tSize = t.length();
        int is = 0, it = 0;
        while(is < sSize && it < tSize) {
            if(s[is] == t[it]) {
                is++;                
            }
            it++;            
        }
        return is == sSize;
        
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().isSubsequence(s, t) << endl;
    return 0;
}