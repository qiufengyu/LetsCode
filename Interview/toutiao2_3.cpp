//
// Created by Fengyu Qiu on 2018/8/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        string dummy;
        getline(cin, dummy);
        vector<string> v;
        while(n--) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        bool flag = false;
        for(int i = 0; i< v.size(); ++i) {
            string x = v[i];
            string tx = string(x);
            string xx = tx.append(tx);
            string xxx = string(xx);
            reverse(xx.begin(), xx.end());
            int xlen = x.length();
            for(int j = i + 1; j<v.size(); ++j) {
                string y = v[j];
                if(xlen == y.length()) {
                    if(xx.find(y) != string::npos || xxx.find(y) != string::npos) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"Yeah"<<endl;
        else cout<<"Sad"<<endl;
    }
    return 0;
}
