#include "seq_list_utils.h"
/*
  合并两个有序顺序表
*/

bool merge_sorted_List(Linear_List &L1, Linear_List &L2, Linear_List &L3)
{
    if (L1.length + L2.length > L3.length)
    {
        return false;
    }

    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] < L2.data[j])
        {
            L3.data[k] = L1.data[i];
            i++;
        }
        else
        {
            L3.data[k] = L2.data[j];
            j++;
        }
        k++;
    }
    while (i < L1.length)
    {
        L3.data[k] = L1.data[i];
        i++;
        k++;
    }
    while (j < L2.length)
    {
        L3.data[k] = L2.data[j];
        j++;
        k++;
    }
    L3.length = k;
    return true;
}

int main()
{
    Linear_List L1, L2, L3;
    L1.length = 5;
    L2.length = 7;
    L3.length = 30;
    L1.data[0] = 1;
    L1.data[1] = 3;
    L1.data[2] = 5;
    L1.data[3] = 7;
    L1.data[4] = 9;
    L2.data[0] = 2;
    L2.data[1] = 4;
    L2.data[2] = 6;
    L2.data[3] = 8;
    L2.data[4] = 10;
    L2.data[5] = 12;
    L2.data[6] = 14;
    if (merge_sorted_List(L1, L2, L3))
    {
        cout << "Merge successfully!" << endl;
        for (int i = 0; i < L3.length; i++)
        {
            cout << L3.data[i] << " ";
        }
    }
    else printf("Failed to merge!");
    return 0;
}