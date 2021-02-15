#include "../header.h"

 class Iterator {
	struct Data;
 	Data* data;
public:
	Iterator(const vector<int>& nums);
 	Iterator(const Iterator& iter);
 	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
  int pNum;
  bool pHasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    pHasNext = Iterator::hasNext();
      if (pHasNext) {
        pNum = Iterator::next();        
      }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
      return pNum;  
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
    int lastNum = pNum;
    if (Iterator::hasNext()) {
      pNum = Iterator::next();
      pHasNext = true;
    } else {
      pHasNext = false;
    }
    return lastNum;	    
	}
	
	bool hasNext() const {
	    return pHasNext;
	}
};