#include "../header.h"

unordered_map<int, string> mp1 {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {0, "Zero"}};
unordered_map<int, string> mp2 {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
unordered_map<int, string> mp3 {{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};

string stringJoin(const vector<string> &strs, const string delim)
{
    if (strs.size() == 0) return "";
    vector<char> res;
    for (int i = 0; i < strs.size()-1; ++i)
    {
        for (auto c: strs[i]) res.push_back(c);
        for (auto c: delim) res.push_back(c);
    }
    for (auto c: strs[strs.size()-1]) res.push_back(c);
    return string{res.begin(), res.end()};
}


class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> res;
        if (num / 1000000000 > 0) {
            auto parts = helper(num / 1000000000);
            for (auto const& s: parts) {
                res.push_back(s);
            }
            res.push_back("Billion");
        }
        num = num % 1000000000;
        if (num / 1000000 > 0) {
            auto parts = helper(num / 1000000);
            for (auto const& s: parts) {
                res.push_back(s);
            }
            res.push_back("Million");
        }
        num = num % 1000000;
        if (num / 1000 > 0) {
            auto parts = helper(num / 1000);
            for (auto const& s: parts) {
                res.push_back(s);
            }
            res.push_back("Thousand");
        }
        num = num % 1000;
        auto parts = helper(num);
        for (auto const& s: parts) {
            res.push_back(s);
        }
        return stringJoin(res, " ");
    }

    vector<string> helper(int x) {
        if (x == 0) {
            return {};
        }
        vector<string> parts;
        int h = x / 100;
        if (h > 0) {
            parts.push_back(mp1[h]);
            parts.push_back("Hundred");
        }
        int r = x % 100;
        if (r >= 20) {
            parts.push_back(mp3[r / 10 * 10]);
            if ((r % 10) != 0) {
                parts.push_back(mp1[r % 10]);
            }
        } else if (r >= 10) {
            parts.push_back(mp2[r]);
        } else if (r > 0) {
            parts.push_back(mp1[r]);
        }
        return parts;
    }
};