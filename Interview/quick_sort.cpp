//
// Created by Godfray on 2018/3/26.
//

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int i): val(i), next(nullptr) {}
};


void swap(Node *a, Node *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

Node* partition(Node *h, Node *e) {
    int pivot = h->val;
    Node *p = h;
    Node *q = p->next;
    while(q != e) {
        if(q->val < pivot) {
            p = p->next;
            swap(p, q);
        }
        q = q->next;
    }
    swap(p, h);
    return p;
}

void qsort(Node *h, Node *e) {
    if(h != e) {
        Node *p = partition(h, e);
        qsort(h, p);
        qsort(p->next, e);
    }
}


int partition(int *a, int start, int end) {
    int pivot = a[start];
    int left = start - 1;
    int right = end + 1;
    while(1) {
        do {
            left++;
        } while(a[left] < pivot);
        do {
            right--;
        } while(a[right] > pivot);
        if (left >= right) {
            return right;
        }
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }
}

int partition2(int *a, int start, int end) {
    int pivot = a[end];
    int i = start;
    for(int j = start; j<end; ++j) {
        if (a[j] < pivot) {
            // i 记录了小于 pivot 的位置
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    int temp = a[i];
    a[i] = a[end];
    a[end] = temp;
    return i;
}

void quickSort(int *a, int start, int end) {
    if(start < end) {
        int mid = partition2(a, start, end);
        quickSort(a, start, mid);
        quickSort(a, mid + 1, end);
    }
}

int main() {
    int a[15] = {5,3,1,4,9,0,2,4,8,7,3,1,8,7,7};
    quickSort(a, 0, 14);
    for(int i = 0; i<15; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}