#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
    ~ListNode() {}
};

pair<ListNode *, ListNode *> reverseList(ListNode *head, ListNode *tail)
{
    ListNode *pre = tail->next;
    ListNode *end = tail->next;
    ListNode *cur = head;
    while (cur != end)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return {tail, head};
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head)
        return head;
    ListNode *ret = head;
    ListNode *tail = nullptr;
    while (head)
    {
        ListNode *node = head;
        for (int i = 0; i < k - 1; i++)
        {
            node = node->next;
            if (!node)
                return ret;
        }

        ListNode *start = head;
        ListNode *end = node;
        auto p = reverseList(start, end);
        if (!tail)
        {
            ret = p.first;
        }
        else
            tail->next = p.first;
        tail = p.second;
        head = p.second->next;
    }
    return ret;
}

int main()
{
    return 0;
}
