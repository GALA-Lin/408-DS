#include "list_utils.h"
#include <stdlib.h>

// 创建空节点
struct ListNode* createNode() {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {  // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

// 创建并初始化新节点
struct ListNode* createNode(ElemType val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {  // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// 打印链表中的所有节点
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
// 打印带头结点的链表（跳过头结点）
void printListWithHead(struct ListNode* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    
    ListNode *p = head->next;  // 跳过带头结点
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << " -> NULL" << endl;
}

// 释放链表占用的所有内存
void freeList(LinkList &L) {
    while (L != NULL) {
        LinkList temp = L;
        L = L->next;
        free(temp);
    }
}
