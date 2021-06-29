#include "../header.h"

struct Node {
  string word;
  int index;
  Node(string w, int i): word(w), index(i) {}
};

class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
      int ans = 0;
      vector<vector<Node*>> heads(26, vector<Node*>());
      for (auto const &word: words) {
        heads[word[0] - 'a'].push_back(new Node(word, 0));
      }
      for (int i = 0; i < s.size(); ++i) {
        int currentIndex = s[i] - 'a';
        auto oldBucket = heads[currentIndex];
        heads[currentIndex].clear();
        for (Node* n: oldBucket) {
          ++n->index;
          if (n->index == n->word.length()) {
            ans++;
          } else {
            heads[n->word[n->index] - 'a'].push_back(n);
          }
        }
        oldBucket.clear();
      }
      return ans;
  }
};

int main() {
  string s = "dsahjpjauf";
  vector<string> words {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
  cout << Solution().numMatchingSubseq(s, words) << endl;
  return 0;
}