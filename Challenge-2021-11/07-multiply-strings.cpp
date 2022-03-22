#include "../header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<string> products;
        size_t l1 = num1.size(), l2 = num2.size();
        if (l1 < l2) {
            swap(num1, num2);
        }        
        int weight = 0;
        for (int i = num2.size() - 1; i >= 0; --i) {
            products.push_back(muliplyOneDigit(num1, num2[i], weight));
            weight++;
        }
        string res(l1 + l2, '0');
        for (auto const& p: products) {
            add(res, p, l1 + l2);
        }
        int s = 0;
        while (s < l1 + l2) {
            if (res[s] == '0') {
                s++;
            } else {
                break;
            }
        }
        return res.substr(s);
    }

    void add(string& res, const string& p, const int l) {
        int diff = l - p.size(), carry = 0, s = 0;
        int i = p.size() - 1;
        while (i >= 0) {
            s = res[i + diff] - '0' + p[i] - '0' + carry;
            res[i + diff] = (s % 10) + '0';
            carry = s / 10;
            --i;
        }

        while (carry > 0) {
            s = res[i + diff] - '0' + carry;
            res[i + diff] = (s % 10) + '0';
            carry = s / 10;
            --i;
        }
    }
    
    string muliplyOneDigit(const string& num, char c, int weight) {      
        if (c == '0') {
            return "0";
        } else if (c == '1') {
            size_t l = num.size();
            string res(l + weight, '0');
            for (int i = 0; i < l; ++i) {
                res[i] = num[i];
            }
            return res;
        } else {
            size_t l = num.size();
            string res(l + weight + 1, '0');
            int m = c - '0', carry = 0, p = 0;
            for (int i = l - 1; i >= 0; --i) {
                p = m * (num[i] - '0') + carry;
                res[i+1] = '0' + (p % 10);
                carry = p / 10;
            }
            if (carry > 0) {
                res[0] = '0' + carry;
                return res;
            } else {
                return res.substr(1);
            }
        }
    }    
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().multiply(s1, s2) << endl;
    return 0;
}