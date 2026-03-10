#include "list_utils.h"

/*
  带头节点的单链表，删除最小值
*/

void Del_Min(LinkList &L)
{
    if (L == NULL || L->next == NULL) // 空链表或只有一个节点
        return;
    ListNode *minPre = L;        // 指向最小值节点的前一个节点
    ListNode *minNode = L->next; // 指向最小值节点
    ListNode *pre = L;           // 当前节点的前一个节点
    ListNode *q = L->next;       // 当前节点
    while (q != NULL)
    {
        if (q->data < minNode->data)
        {
            minNode = q;
            minPre = pre;
        }
        pre = q;
        q = q->next;
    }
    // 删除最小值节点
    minPre->next = minNode->next;
    delete minNode; // 释放被删除节点的内存
}

int main()
{
    LinkList L = NULL;
    L = createNode(5);
    L->next = createNode(3);
    L->next->next = createNode(7);
    L->next->next->next = createNode(2);
    L->next->next->next->next = createNode(8);
    L->next->next = createNode(4);
    printList(L);
    Del_Min(L);
    printList(L);
    freeList(L);
    return 0;
}