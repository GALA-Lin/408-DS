#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <iostream>
using namespace std;

#define ElemType int

typedef struct ListNode {
    ElemType data;
    struct ListNode *next;
} ListNode, *LinkList;

struct ListNode* createNode(ElemType val);
void printList(struct ListNode* head);
void freeList(LinkList &L);

#endif // LIST_UTILS_H
