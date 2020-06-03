//
// Created by Godfray on 2018/3/12.
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.length();
        // if s is an empty string, then return 0
        int max_length = 0;
        int i = 0, j = 0;
        set<char> subset;
        while(i < sz && j < sz) {
            if(subset.find(s[j]) == subset.end()) {
                subset.insert(s[j]);
                j++;
                max_length = ((j-i)>max_length)?(j-i):max_length;
            }
            else {
                subset.erase(s[i]);
                i++;
            }
        }
        return max_length;
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}