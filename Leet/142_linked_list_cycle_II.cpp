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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> nodeSet;
        ListNode *p = head;
        while(p != NULL) {
            if (nodeSet.find(p) != nodeSet.end()) {
                return p;
            }
            else {
                nodeSet.insert(p);
            }
            p = p ->next;
        }
        return NULL;
    }
};


/**
 *  Step 1: Determine whether there is a cycle

    1.1) Using a slow pointer that move forward 1 step each time

    1.2) Using a fast pointer that move forward 2 steps each time

    1.3) If the slow pointer and fast pointer both point to the same location after several moving steps, there is a cycle;

    1.4) Otherwise, if (fast->next == NULL || fast->next->next == NULL), there has no cycle.

    Step 2: If there is a cycle, return the entry location of the cycle

    2.1) L1 is defined as the distance between the head point and entry point

    2.2) L2 is defined as the distance between the entry point and the meeting point

    2.3) C is defined as the length of the cycle

    2.4) n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer

    According to the definition of L1, L2 and C, we can obtain:

    the total distance of the slow pointer traveled when encounter is L1 + L2

    the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C

    Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:

    2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)

    It can be concluded that the distance between the head location and entry location is equal to the distance between the meeting location and the entry location along the direction of forward movement.

    So, when the slow pointer and the fast pointer encounter in the cycle, we can define a pointer “entry” that point to the head, this “entry” pointer moves one step each time so as the slow pointer. When this “entry” pointer and the slow pointer both point to the same location, this location is the node where the cycle begins.
 */
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        while(fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 根据推导可知，
            if(slow == fast) {
                ListNode *entry = head;
                while(entry != slow) {
                    // 当 entry 再走 L1 长度时，slow 指针正好也会在入口处，相当于走了环上 -L2 的距离
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
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
    n5->next = n3;
    // n1->next = NULL;

    ListNode *head = n1;
    if(Solution().detectCycle(head))
        cout<<*((int *)Solution().detectCycle(head))<<endl;
    else {
        cout<<"No circle!"<<endl;
    }

    return 0;
}



