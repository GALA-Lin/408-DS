#include <iostream>
using namespace std;
/*
  带头节点的单链表，删除最小值
*/
// 定义元素类型为整数
#define ElemType int

// 定义单链表节点结构
typedef struct ListNode 
{
    ElemType data;
    struct ListNode *next;
}ListNode, *LinkList;

void Del_Min(LinkList &L)
{
    if (L == NULL || L->next == NULL) // 空链表或只有一个节点
        return;
    ListNode *pre = L, *q = L->next;
    while (q != NULL)
    {
        if (q->data < pre->data)
            pre = q;
        q = q->next;
    }
    pre->next = pre->next->next; // 删除pre节点
}

int main(){
    
}