#include "../header.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        string compress = "";
        char cur = chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (cur != chars[i]) {
                compress.push_back(cur);
                if (count > 1) {
                    compress += to_string(count);
                }
                count = 1;
                cur = chars[i];
            } else {
                ++count;
            }            
        }
        if (count > 0) {
            compress.push_back(cur);
            if (count > 1) {
                compress += to_string(count);
            }
        }
        // cout << compress << endl;
        return compress.size();
    }
};

int main() {
    vector<char> chars {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << Solution().compress(chars) << endl;
    return 0;
}