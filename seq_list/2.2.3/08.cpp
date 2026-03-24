#include "seq_list_utils.h"
/*
  有序递增顺序表，查找值为X的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍然递增有序。
*/

bool SerchSwapOrInsert(Linear_List &L, Element_Type X) {
    int i = 0;
    while (i < L.length && L.data[i] < X) {
        i++;
    }
    if (i < L.length && L.data[i] == X) {
        // 找到了，将其与后继元素位置相交换
        L.data[i] = L.data[i + 1];
        L.data[i + 1] = X;
        return true;
    }
    else {
        // 没找到，将其插入表中并使表中元素仍然递增有序
        for (int j = L.length - 1; j >= i; j--) {
            L.data[j + 1] = L.data[j];
        }
        L.data[i] = X;
        L.length++;
    }
    return false;
}

int main() {
    Linear_List L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 5;
    L.data[3] = 7;
    L.data[4] = 9;
    bool flag = SerchSwapOrInsert(L, 4);
    printf("flag = %d\n", flag);
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    printf("\n");
    flag = SerchSwapOrInsert(L, 4);
    printf("flag = %d\n", flag);
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    return 0;
}