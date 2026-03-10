#include "seq_list_utils.h"
/*
  删除所有值为X的元素
*/

void delete_X_optimized(Linear_List &list, Element_Type X)
{
    int i = 0; // 用于遍历
    int j = 0; // 用于记录非X元素的位置
    while (i < list.length)
    {
        if (list.data[i] != X)
        {
            list.data[j] = list.data[i];
            j++;
        }
        i++;
    }
    list.length = j;
}//O(n)

int main()
{
    Linear_List list;
    list.length = 5;
    list.data[0] = 1;
    list.data[1] = 2;
    list.data[2] = 3;
    list.data[3] = 3;
    list.data[4] = 5;
    cout << "Before delete X: ";
    for (int i = 0; i < list.length; i++)
    {
        cout << list.data[i] << " ";
    }
    cout << endl;
    delete_X_optimized(list, 3);
    cout << "After delete X: ";
    for (int i = 0; i < list.length; i++)
    {
        cout << list.data[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
void delete_X(Linear_List &list, Element_Type X)
{
    int i = 0;
    while (i < list.length)
    {
        if (list.data[i] == X)
        {
            for (int j = i; j < list.length - 1; j++)
            {
                list.data[j] = list.data[j + 1];
            }
            list.length--;
        }
        else
        {
            i++;
        }
    }
}O(n^2)
*/
