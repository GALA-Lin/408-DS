#include "seq_list_utils.h"
/*
  删除线性表最小值，由函数返回被删除元素值
  空出位置由末尾元素补充
*/

bool deleteMin(Linear_List &L, Element_Type &deleted_value)
{
    if (L.length == 0)
        return false; // 空表
    deleted_value = L.data[0];
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < deleted_value)
        {
            deleted_value = L.data[i];
        }
    }
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == deleted_value)
        {
            L.data[i] = L.data[L.length - 1];
            L.length--;
            return true;
        }
    }
    return false; // 未找到最小值
}

int main()
{
    Linear_List L;
    L.length = 5;
    L.data[0] = 3;
    L.data[1] = 1;
    L.data[2] = 4;
    L.data[3] = 1;
    L.data[4] = 5;
    cout << "Before deleteMin: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
    Element_Type value = 0;
    if (deleteMin(L, value))
    {
        cout << "After deleteMin: ";
        for (int i = 0; i < L.length; i++)
        {
            cout << L.data[i] << " ";
        }
        cout << endl;
        cout << "The minimum value is: " << value << endl;
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
    return 0;
}