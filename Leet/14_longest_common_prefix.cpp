//
// Created by Godfray on 2018/3/19.
//

#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>


using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string ret = strs[0];
        for(int i = 1; i<strs.size(); ++i) {
            ret = commonPrefix(ret, strs[i]);
        }
        return ret;
    }

    string commonPrefix(string s1, string s2) {
        string ret = "";
        int length = s1.length() < s2.length() ? s1.length() : s2.length();
        for(int i = 0; i<length; ++i) {
            if(s1[i] == s2[i]) {
                ret.push_back(s1[i]);
            }
            else {
                break;
            }
        }
        return ret;
    }
};

int main() {
    string a = "abcdefg";
    string b = "abceefdsfs";
    string c = "abcddefdsfs";
    string d = "abcdeddddddd";
    vector<string> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    string out = Solution().longestCommonPrefix(v);
    cout<<out<<endl;

}