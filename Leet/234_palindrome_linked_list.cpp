//
// Created by Godfray on 2018/3/12.
//

#include <iostream>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int i): val(i) , next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 简单方法，创建一个新的反转链表，再依次比较，空间需要 O(n)
        // 稍微带一点优化的方法：先计算长度，再根据位置关系进行比较？？时间复杂度 O(n^2)
        // 如果要实现 O(n) 时间，O(1) 空间的话：
        // 1. 找到中间节点，保存下这个 mid 指针，可以使用两个指针，也可以先计数后遍历，O(2n) 最多
        // 2. 翻转链表的前半部分
        // 3. 比较翻转后的前半部分与后半部分是否一致
        ListNode *tail = NULL;
        ListNode *p = head;
        while( p != NULL ) {
            ListNode *temp = new ListNode(p->val);
            temp->next = tail;
            tail = temp;
            p = p->next;
        }
        ListNode *p1 = head;
        ListNode *p2 = tail;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}