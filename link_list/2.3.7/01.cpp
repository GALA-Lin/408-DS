#include "D:\408-DS\List_Utils\list_utils.h"

// 删除链表中所有值为x的节点
void deleteNode(LinkList &L, ElemType x) { // 等于 LinkNode* &L, 即引用传参
    ListNode* pre = L, *curr = L->next, *q;
    while (curr != NULL) {
        if (curr->data == x) {
            q = curr->next;
            free(curr);
            curr = q;
            pre->next = q;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
}

// 测试主函数
int main() {
    // 创建链表：2 -> 4 -> 2 -> 6 -> 2 -> NULL
    struct ListNode* head = createNode(2);
    head->next = createNode(4);
    head->next->next = createNode(2);
    head->next->next->next = createNode(6);
    head->next->next->next->next = createNode(2);

    printf("原链表：");
    printList(head);

    ElemType x = 2;
    deleteNode(head, x);  // 删除所有值为2的节点

    printf("删除值为%d后的链表：", x);
    printList(head);

    freeList(head);  // 释放链表内存
    return 0;
}
