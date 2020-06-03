//
// Created by Godfray on 2018/3/19.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string romanPieces[] = { "","I","II","III","IV","V","VI","VII","VIII","IX",
                                 "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                                 "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                                 "","M","MM","MMM","MMMM" };
        return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20]
               +romanPieces[(num/10)%10+10]+romanPieces[num%10];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
