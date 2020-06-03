//
// Created by Godfray on 2018/3/8.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        unsigned int length = s.length();
        string ret = "";
        // cout<<length<<endl;
        if(numRows == 1 || numRows >= length) {
            return s;
        }
        int gap = 2 * numRows - 2;
        // 第一行
        int j = 0;
        for(int i = 0; i<length; i += gap) {
            ret.push_back(s[i]);
        }
        // 第 2 到 (numRows -1) 行
        for(int i = 1; i<numRows -1; ++i) {
            ret.push_back(s[i]);;
            for(int k = gap; k<length+numRows-2; k += gap) {
                if( k-i < length)
                    ret.push_back(s[k-i]);
                if( k+i < length)
                    ret.push_back(s[k+i]);
            }
        }
        // 最后一行
        for(int i = numRows-1; i<length; i+= gap) {
            ret.push_back(s[i]);;
        }
        return string(ret);
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}