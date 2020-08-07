#include "header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int sa = a.length(), sb = b.length();
        int sc = max(sa, sb);
        string c(sc, '0');
        if (sa < sb) {            
            int d = sb - sa;
            while (d > 0) {
                a.insert(a.begin(), '0');
                d--;
            }
        } else {
            int d = sa - sb;
            while (d > 0) {
                b.insert(b.begin(), '0');
                d--;
            }
        }
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        int carry = 0;
        for (int i = sc - 1; i >= 0; i--) {
            if (a[i] == '1' && b[i] == '1') {
                c[i] = carry == 1 ? '1' : '0';
                carry = 1;                
            } else if (a[i] == '0' && b[i] == '0') {
                c[i] = carry == 1 ? '1' : '0';
                carry = 0;
            } else {
                c[i] = carry == 1 ? '0' : '1';
                carry = carry == 1 ? 1 : 0;
            }
        }
        if (carry == 1) {
            c.insert(c.begin(), '1');
        }
        return c;        
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    cout << Solution().addBinary(a, b) << endl;
    return 0;
}