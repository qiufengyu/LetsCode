//
// Created by Fengyu Qiu on 2018/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t found = -1;
        for(auto x: s) {
            found = t.find(x, found+1);
            if(found == string::npos) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    auto res = Solution().isSubsequence("axc", "ahbgdc");
    cout<<res<<endl;
    return 0;
}
