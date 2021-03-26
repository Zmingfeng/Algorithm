#include<iostream>
#include<cstdio>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val, ListNode* _next = nullptr) : val(_val), next(_next) {}
    ~ListNode() {}

};

ListNode* rotateList(ListNode* head, int k) {
    if(!head) return nullptr;
    ListNode* node = head;
    int len = 0;
    while(node->next) {
        len++;
        node = node->next;
    }
    node->next = head;
    k = k % (len + 1) + 1;
    while(--k > 0) {
        cout << node->val << ' ';
        node = node->next;
    }
    cout << endl;
    ListNode* ret =  node->next;
    node->next = nullptr;
    return ret;
}


int main() {
    return 0;
}