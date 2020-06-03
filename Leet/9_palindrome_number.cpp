//
// Created by Godfray on 2018/3/12.
//

#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        // 使用 LeetCode - 7 的整数翻转算法
        int xx = x;
        if (x < 0)
            return false;
        int y = 0;
        // 不管x 是 +0 或 -0 都认为无效
        while(x) {
            int temp = y * 10 + x % 10;
            // 从相关讨论中得到的做法判断溢出
            if(temp / 10 != y)
                return false;
            y = temp;
            x /= 10;
        }
        return y == xx;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}