//
// Created by Godfray on 2018/3/8.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // 仔细推导后，发现正负都可以处理
        // 因为负数的模运算得到的也是一个负数
        int y = 0;
        // 不管x 是 +0 或 -0 都认为无效
        while(x) {
            int temp = y * 10 + x % 10;
            // 从相关讨论中得到的做法判断溢出
            if(temp / 10 != y)
                return 0;
            y = temp;
            x /= 10;
        }
        return y;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

/*
 *      bool flag = false;
        vector<int> temp;
        int xx = x;
        if (x < 0) {
            flag = true;
            xx = -x;
        }
        while(xx > 0) {
            temp.push_back(xx % 10);
            xx /= 10;
        }
        long long y = 0;
        for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
            y *= 10;
            y += *it;
        }
        if (flag) {
            y = -y;
        }
        // 从相关讨论中得出的
        return (y < INT_MIN || y > INT_MAX) ? 0 : (int)y;
 */