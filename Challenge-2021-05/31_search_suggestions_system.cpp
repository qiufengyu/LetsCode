#include "../header.h"

#define VOCAB_SIZE 26

class Trie {
  Trie* nodes[VOCAB_SIZE];
  vector<string> words;
public:
  Trie() {
    for (int i = 0; i < VOCAB_SIZE; ++i) {
      nodes[i] = nullptr;
    }
  }
  ~Trie() {
    for (int i = 0; i < VOCAB_SIZE; ++i) {
      if (nodes[i]) {
        delete nodes[i];
      }
    }
  }
  void addWord(const string& word) {
    Trie* root = this;
    for (char c: word) {
      int index = c - 'a';
      if (root->nodes[index] == nullptr) {
        root->nodes[index] = new Trie();
      }
      root = root->nodes[index];
      if (root->words.size() < 3) {
        root->words.push_back(word);
      }
    }
  }

  vector<vector<string>> getWords(const string& prefix) {
    Trie* root = this;
    vector<vector<string>> ans(prefix.size());
    for (int i = 0; i < prefix.size(); ++i) {
      char c = prefix[i];
      root = root->nodes[c - 'a'];
      if (root == nullptr) {
        break;
      }
      for (auto const & word: root->words) {
        ans[i].push_back(word);
      }
    }
    return ans;
  }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        Trie* trie = new Trie();
        for (auto const& product: products) {
          trie->addWord(product);
        }
        return trie->getWords(searchWord);
    }
};

int main() {
  vector<string> products {"mobile","mouse","moneypot","monitor","mousepad"};
  string searchWord = "mouse";
  vector<vector<string>> res = Solution().suggestedProducts(products, searchWord);
  print_vector(res);
  return 0;
}