#include "header.h"

class Solution {
public:
    string validIPAddress(string IP) {
        const string invalid = "Neither";
        const string ipv4 = "IPv4";
        const string ipv6 = "IPv6";
        vector<string> v;
        string temp;
        if (IP.find('.') == string::npos) {
            // can be IPV6, 8 groups to be checked            
            for (int i = 0; i < IP.length(); i++) {
                if (IP[i] == ':') {
                    if (temp.length() < 1) {
                        return invalid;
                    } else {
                        v.push_back(temp);
                        temp.clear();
                    }
                } else {
                    temp.push_back(IP[i]);
                }
            }
            v.push_back(temp);
            if (v.size() == 8) {
                auto ipv6Token = regex("[0-9a-fA-F]+");
                int validSum = 0;
                for (auto &s: v) {
                    if (regex_match(s, ipv6Token) && s.length() <= 4) {
                        validSum++;
                    }
                }
                if (validSum == 8) {
                    return ipv6;
                }
            }            
        } else {
            for (int i = 0; i<IP.length(); i++) {
                if (IP[i] == '.') {
                    if (temp.length() < 1) {
                        return invalid;
                    } else {
                        v.push_back(temp);
                        temp.clear();
                    }
                } else {
                    temp.push_back(IP[i]);
                }
            }
            v.push_back(temp);
            for (auto &x: v) {
                cout << x << endl;
            }        
            if (v.size() == 4) {
                int validSum = 0;
                auto ipv4Token = regex("[1-9][0-9]?[0-9]?");
                for (auto &s: v) {
                    if ((s.length() == 1 && s[0] == '0') || (regex_match(s, ipv4Token) && stoi(s) <= 255)) {
                        validSum++;
                    }
                }
                if (validSum == 4) {
                    return ipv4;
                }
            }                        
        }
        return invalid;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().validIPAddress(s) << endl;
    return 0;
}