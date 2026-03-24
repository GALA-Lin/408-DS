#include "list_utils.h"
/*
  给定两个单链表，试分析找出两个链表的公共结点
*/
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    ListNode* pA = headA;
    ListNode* pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}

int main() {
    LinkList headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = createNode(4);
    headA->next->next = createNode(5);

    LinkList headB = createNode(6);
    headB->next = createNode(7);
    headB->next->next = createNode(8);
    
    headB->next->next = headA->next;

    printf("List A:\n");
    printList(headA);
    printf("List B:\n");
    printList(headB);

    ListNode* p = getIntersectionNode(headA, headB);
    if (p == NULL) {
        printf("No intersection node.\n");
    } else {
        printf("Intersection node value is %d.\n", p->data);
    }
    // 需要写新的free函数 因为headB->next->next->next = headA->next->next;
    // 简单free只能释放A/B，而不释放AB相交前的节点，导致headA和headB的内存泄漏

    // freeList(headA);
    // freeList(headB);
    return 0;
}