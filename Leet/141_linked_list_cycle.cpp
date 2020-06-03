//
// Created by Godfray on 2018/3/12.
//

#include <iostream>
#include <cassert>
#include <set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodeSet;
        ListNode *p = head;
        while(p != NULL) {
            if (nodeSet.find(p) != nodeSet.end()) {
                return true;
            }
            else {
                nodeSet.insert(p);
            }
            p = p ->next;
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        while(fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    ListNode *n3 = new ListNode(3);
    n2->next = n3;
    ListNode *n4 = new ListNode(4);
    n3->next = n4;
    ListNode *n5 = new ListNode(5);
    n4->next = n5;
    // n5->next = n3;
    // n1->next = NULL;

    ListNode *head = n1;

    cout<<Solution2().hasCycle(head)<<endl;

    return 0;
}



