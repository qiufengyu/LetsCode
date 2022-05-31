#include "../header.h"

const map<char, string> m {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        deque<string> q;
        for (int i = 0; i < m.at(digits[0]).size(); ++i) {
            q.push_back(string("") + (m.at(digits[0])[i]));
        }
        for (int i = 1; i < digits.size(); ++i) {
            cout << "current char: " << digits[i] << endl;
            string ss = m.at(digits[i]);
            int sz = q.size();
            while (sz > 0) {
                string s = q.front();
                q.pop_front();
                for (char c: ss) {
                    q.push_back(s + c);
                    cout << "push " << (s + c) << endl;
                }
                --sz;
            }
        }
        vector<string> res(q.begin(), q.end());
        return res;
    }
};

int main() {
    string digits;
    cin >> digits;
    vector<string> res = Solution().letterCombinations(digits);
    print_vector<string>(res);
    return 0;
}