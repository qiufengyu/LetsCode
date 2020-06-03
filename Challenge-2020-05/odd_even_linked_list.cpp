#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
  public:
    ListNode* oddEvenList(ListNode* head) {
        if (head && head->next)  {
            ListNode *tail = head;     
            ListNode *prev = head->next;
            ListNode *p = prev->next;
            ListNode *ep = new ListNode(0);
            ListNode *es = ep;
            while (p) {
                cout << "prev: " << prev->val << ", p: " << p->val << ", ep: " << ep->val << endl; 
                tail->next = p;
                tail = tail->next;
                ep->next = prev;
                ep = ep->next;                
                if (p->next) {           
                    prev = p->next;
                    p = prev->next;
                } else {                  
                    break;
                }
            }
            if (p == nullptr) {
                ep->next = prev;
                ep = ep->next;
            }
            ep->next = nullptr;
            tail->next = es->next;
        }
        return head;
    }
};

void printList(ListNode *head) {
    while (head->next) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << "->NULL" << endl;
}

int main() {    
    int x = 0;
    cin >> x;
    ListNode *head = new ListNode(x);
    ListNode *p = head;
    while (cin >> x) {
        ListNode *n = new ListNode(x);
        p->next = n;
        p = p->next;
    }
    cin.clear();
    ListNode *r = Solution().oddEvenList(head);
    printList(r);
    return 0;
}