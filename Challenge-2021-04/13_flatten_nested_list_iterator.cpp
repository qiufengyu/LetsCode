#include "../header.h"


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
 };
 

class NestedIterator {
  stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >=0; --i) {
          s.push(nestedList[i]);
        }
    }
    
    int next() {
      NestedInteger ni = s.top();
      s.pop();
      return ni.getInteger();        
    }
    
    bool hasNext() {
      while (!s.empty()) {
        NestedInteger ni = s.top();
        if (ni.isInteger()) {
          return true;
        }
        s.pop();
        auto l = ni.getList();
        for (int i = l.size() - 1; i >= 0; --i) {
          s.push(l[i]);
        }
      }
      return false;        
    }
};