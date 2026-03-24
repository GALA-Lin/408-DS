#include "list_utils.h"
/*
  设在一个带表头结点的单链表中，所有结点的元素值无序，
  试编写一个函数，删除表中所有处于给定的两个值（作为函数参数给出）之间的元素（若存在）。
*/

void deleteBetween(LinkList &L, ElemType minVal, ElemType maxVal)
{
    if (L == NULL || L->next == NULL)
    {
        return;
    }
    if (minVal > maxVal)
    {
        swap(minVal, maxVal);
    }
    // p指向当前要检查的结点的前一个结点
    ListNode *prev = L;
    ListNode *curr = L->next; // q指向当前要检查的结点

    while (curr != NULL)
    {
        // 如果当前结点的值在区间内，则删除该结点
        if (curr->data >= minVal && curr->data <= maxVal)
        {
            prev->next = curr->next; // 将当前结点从链表中移除
            delete curr;             // 释放被删除结点的内存
            curr = prev->next;       // q指向下一个待检查的结点
        }
        else
        {
            // 值不在区间内，继续向后遍历
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    LinkList L = createNode(2);
    L->next = createNode(4);
    L->next->next = createNode(5);
    L->next->next->next = createNode(6);
    L->next->next->next->next = createNode(2);
    L->next->next->next->next->next = createNode(8);
    printf("原链表：\n");
    printList(L);
    deleteBetween(L, 4, 6);
    printf("删除4-6之间的元素后的链表：\n");
    printList(L);
    freeList(L);
    return 0;
}