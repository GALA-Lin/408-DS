#include "seq_list_utils.h"
/*
  有序顺序表中删除所有重复值
  有序，所以只考虑相邻元素重复否
*/ 
void delete_sorted_seq_list_duplicates(Linear_List &L)
{
    if (L.length <= 1) {
        // 如果长度小于等于1，不需要删除重复值，直接返回
        return;
    }
    int new_length = 0; // 新列表的长度
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] != L.data[new_length])//原列表的元素与新列表的最后一个元素不相等，则添加到新列表中
        {
            L.data[++new_length] = L.data[i];
        }
    }
    L.length = new_length + 1; // 更新列表的实际长度
}

int main()
{
    Linear_List L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 3;
    L.data[3] = 3;
    L.data[4] = 4;
    cout << "Before delete duplicates: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
    delete_sorted_seq_list_duplicates(L);
    cout << "After delete duplicates: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
//(走遍历-无关有序否)
void delete_duplicates(Linear_List &L)
{
    int i, j;
    for (i = 0; i < L.length - 1; i++)
    {
        for (j = i + 1; j < L.length; j++)
        {
            if (L.data[i] == L.data[j])
            {
                for (int k = j; k < L.length - 1; k++)
                {
                    L.data[k] = L.data[k + 1];
                }
                L.length--;
                j--;
            }
        }
    }
}
*/