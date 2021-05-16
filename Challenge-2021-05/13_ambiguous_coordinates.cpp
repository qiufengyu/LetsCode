#include "../header.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        for (int i = 2; i < s.size() - 1; ++i) {
          for (auto &left: findPossibleNumber(s, 1, i)) {
            for (auto &right: findPossibleNumber(s, i, s.size() - 1)) {
              res.push_back("(" + left + ", " + right + ")");
            }
          }
        }
        return res;
    }

    vector<string> findPossibleNumber(const string& s, int start, int end) {
      // if S == "": return []
      // if S == "0": return [S]
      // if S == "0XXX0": return []
      // if S == "0XXX": return ["0.XXX"]
      // if S == "XXX0": return [S]
      // return [S, "X.XXX", "XX.XX", "XXX.X"...]
      if (s[end-1] == '0') {
        if (s[start] == '0') {
          if (end - start == 1) {
            return {"0"};
          }
          else {
            return {};
          }
        }
        else {
          return {s.substr(start, end - start)};
        }
      }
      else {
        if (s[start] == '0') {
          return {"0." + s.substr(start + 1, end - start - 1)};
        }
        else {
          vector<string> p;
          for (int i = 1; i < end - start; ++i) {
            p.push_back(s.substr(start, i) + "." + s.substr(start + i, end - start - i));
          }
          p.push_back(s.substr(start, end - start));
          return p;
        }        
      }      
    }
};

int main() {
  string s;
  cin >> s;
  vector<string> res = Solution().ambiguousCoordinates(s);
  print_vector<string>(res);
  return 0;
}
