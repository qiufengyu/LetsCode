#include "../header.h"

inline bool isVowel(char c) {
    return c == 'A' || 
           c == 'E' || 
           c == 'I' || 
           c == 'O' || 
           c == 'U' || 
           c == 'a' ||
           c == 'e' ||
           c == 'i' || 
           c == 'o' ||
           c == 'u';
}

class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> v;
        stringstream ss(S);
        string word;
        const string ma { "ma" } ;
        string a { "" };
        do {            
            ss >> word;
            if (word.length() > 0) {
                char start = word[0];           
                if (!isVowel(start)) {
                    word.erase(word.begin());
                    word.push_back(start);
                }
                word.append("ma");
                a.append("a");
                word.append(a);
                v.push_back(word);
            }
            word.clear();
        } while(ss);
        stringstream sout;
        for (auto const &x: v) {
            // cout << x << "," << endl;
            sout << x << " ";
        }
        string res = sout.str();
        res.erase(res.end()-1);       
        return res;
    }
};

int main() {
    string S {"I speak Goat Latin"};
    string res = Solution().toGoatLatin(S);
    cout << res << endl;
    string expected {"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"};
    cout << res.compare(expected) << endl;
    return 0;
}

