#include "../header.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto const& email: emails) {
            string t;
            for (char c: email) {
                if (c == '.') {
                    continue;
                }
                if (c == '@' || c == '+') {
                    break;
                }
                t.push_back(c);
            }
            t += email.substr(email.find('@'));
            s.insert(t);
        }
        return s.size();
    }
};