#include "../header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        long sz = s.length();
        if (sz == 0) {
            return 0;
        }
        long end = sz - 1;
        while (end >= 0 && s[end] == ' '){
            end--;
        }
        long start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return (int)(end - start);     
    }
};

int main() {
    string s {"Hello World"};
    cout << Solution().lengthOfLastWord(s) << endl;
    return 0;
}