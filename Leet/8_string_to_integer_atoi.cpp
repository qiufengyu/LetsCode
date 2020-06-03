//
// Created by Godfray on 2018/3/8.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        int i = 0;
        bool sign = true; // positive
        while(i < length) {
            if(str[i] == '-') {
                sign = !sign;
                i++;
                break;
            }
            else if(str[i] == '+') {
                i++;
                break;
            }
            else if(str[i] == ' ') {
                i++;
            }
            else {
                break;
            }
        }
        int ans = 0;
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
        // str[i] 开始是非符号、空白符的开始
        while(i < length) {
            int temp = ans * 10 + int(str[i]-'0');
            // cout<<ans<<" "<<temp<<endl;
            if (temp / 10 != ans ) {
                // cout<<"Error"<<endl;
                // 非法的符号
                if (str[i]<='9' && str[i]>='0') // 溢出
                    return sign ? INT_MAX : INT_MIN;
                else {
                    return sign? ans : -ans;
                }
            }
            ans = temp;
            i++;
        }
        return sign? ans : -ans;

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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}