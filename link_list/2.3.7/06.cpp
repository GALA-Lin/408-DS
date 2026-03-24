#include "list_utils.h"

/**
 * 拆分链表 C 为 A 和 B
 * @param C 原链表（带头结点）
 * @param A 输出：存放奇数位置元素，保持原顺序
 * @param B 输出：存放偶数位置元素，逆序存放
 */
void splitList(LinkList &C, LinkList &A, LinkList &B) {
    // 初始化 A 和 B 的头结点
    A = new ListNode;
    A->next = NULL;
    B = new ListNode;
    B->next = NULL;
    
    // 尾插法需要记录 A 的尾结点
    ListNode *tailA = A;
    
    // 遍历原链表 C（跳过带头结点）
    ListNode *p = C->next;
    int count = 1;  // 位置计数器
    
    while (p != NULL) {
        ListNode *temp = p;        // 当前结点
        p = p->next;               // 保存下一个结点
        
        if (count % 2 == 1) {      // 奇数位置：插入到 A（尾插法）
            tailA->next = temp;
            tailA = temp;
            temp->next = NULL;     // 断开与后续结点的连接
        } else {                   // 偶数位置：插入到 B（头插法，实现逆序）
            temp->next = B->next;
            B->next = temp;
        }
        
        count++;
    }
    
    // 释放原链表的头结点（可选）
    delete C;
    C = NULL;
}

// 测试函数
int main() {
    // 创建原链表 C: a1, b1, a2, b2, ..., an, bn
    // 示例：1, 2, 3, 4, 5, 6
    LinkList C = new ListNode;
    C->next = NULL;
    
    int testData[] = {1, 2, 3, 4, 5, 6};
    ListNode *tail = C;
    for (int i = 0; i < 6; i++) {
        ListNode *newNode = createNode(testData[i]);
        tail->next = newNode;
        tail = newNode;
    }
    
    cout << "原链表 C: ";
    printListWithHead(C);
    
    LinkList A, B;
    splitList(C, A, B);
    
    cout << "链表 A (奇数位置，保持原序): ";
    printListWithHead(A);
    
    cout << "链表 B (偶数位置，逆序): ";
    printListWithHead(B);
    
    // 释放内存
    freeList(A);
    freeList(B);
    
    return 0;
}