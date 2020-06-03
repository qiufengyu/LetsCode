//
// Created by Godfray on 2018/3/8.
//

#include <iostream>

#include <string>
#include <sstream>

#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        unsigned int length = s.length();
        bool dp[1000][1000];
        int max_length = 1;
        int max_start = 0;
        // 初始化，dp(i,j) 表示 s(i,j) 是否为回文串
        for(int i = 0; i<length; ++i) {
            // 单个字符一定是
            dp[i][i] = true;
            // 两个字符的只能相等的时候才是
            if(i < length -1 ) {
                dp[i][i + 1] = (s[i] == s[i + 1]);
                if(dp[i][i+1]) {
                    max_length = 2;
                    max_start = i;
                }
            }
            for(int j = i+2; j<length; ++j) {
                // 其他情况先默认不是
                dp[i][j] = false;
            }
        }

        for(int i = length-2; i>=0; --i) {
            int current_max_length = 0;
            for(int j = i+2; j<length; j++) {
                cout<<i<<","<<j<<endl;
                dp[i][j] = (dp[i+1][j-1]) && (s[i] == s[j]);
                if (dp[i][j]) {
                    current_max_length = j-i+1;
                    if(current_max_length > max_length) {
                        max_length = current_max_length;
                        max_start = i;
                    }
                }
            }
        }

        for(int i = 0; i<length; i++) {
            for(int j = 0; j<length; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return s.substr(max_start, max_length);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}