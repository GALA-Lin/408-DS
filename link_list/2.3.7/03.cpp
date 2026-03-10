#include "list_utils.h"

/*
  带头节点的单链表逆置
*/

// 迭代法
/**
 * 它通过维护 prev（前驱节点）、curr（当前节点）、nextNode（后继节点）三个指针
 * 在一次遍历中逐个反转节点的 next 指针，最终将头节点指向反转后的第一个节点。
 */
void  reverseList(LinkList &L){
    if (L == NULL || L->next == NULL) {
        return;
    }
    ListNode *prev = NULL, *curr = L->next, *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next; // 暂存当前节点的后继元素
        curr->next = prev;     // 反转当前节点的 next 指针
        prev = curr;           // 移动 prev 指针
        curr = nextNode;       // 移动 curr 指针
    }
    L->next = prev; // 头节点的 next 指针指向最后反转的节点
}

int main() {
    LinkList L = createNode();
    L->next = createNode(2);
    L->next->next = createNode(3);
    L->next->next->next = createNode(4);
    L->next->next->next->next = createNode(5);
    L->next->next->next->next->next = createNode(6);
    printList(L);
    reverseList(L);
    printList(L);
    freeList(L);
    return 0;
}


/*
// 头插法 （记录当前和后继）
// 先将头节点的 next 置空，然后遍历原链表的每个节点，把每个节点依次 “插入” 到头节点的后面（头插），最终实现链表整体反转。
void reverseList(LinkList &L) {
    // 如果链表为空或只有一个节点，直接返回
    if (L == NULL || L->next == NULL) {
        return;
    }
    ListNode *curr = L->next, *nextNode = NULL;
    // 将链表头节点的 next 指针置空
    L->next = NULL;
    // 遍历链表，逐个反转节点的 next 指针
    while (curr != NULL)
    {
        nextNode = curr->next; // 暂存当前节点的后继元素
        curr->next = L->next;  // 继承头节点后继元素
        L->next = curr;        // 插入
        curr = nextNode;
    }
}
*/
