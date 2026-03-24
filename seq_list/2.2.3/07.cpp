#include "seq_list_utils.h"
/*
  有一数组A[m+n]，其中存储的元素可以看作两个线性表A1和A2，A1的元素个数为m，A2的元素个数为n。
  请设计一个算法，将A1和A2交换位置，不使用多余的空间。
*/

// 原地交换算法
void Reverse(Element_Type A[], int left, int right){
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    for(int i = 0; i<mid-left+1;i++){
        swap(A[left+i], A[right-i]);
        /*
            交换A[left+i]和A[right-i-1]
            Elem_Type temp = A[left+i];
            A[left+i] = A[right-i-1];
            A[right-i-1] = temp;
        */
    }
}


int main()
{
    int A[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int m = 5, n = 5;
    Reverse(A, 0, m+n-1);
    Reverse(A, m, m+n-1);
    Reverse(A, 0, m-1);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}

/*
异或交换算法：
交换律和结合律：a ^ b ^ a = b ^ (a ^ a) = b ^ 0 = b
自反性：a ^ a = 0
中立性：a ^ 0 = a
void swap(Element_Type A[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        A[i] ^= A[i + n]; // A[i] = A[i] ^ A[i+n]
        A[i + n] ^= A[i]; // A[i+n] = A[i+n] ^ A[i] = A[i+n] ^ A[i] ^ A[i+n] = A[i]
        A[i] ^= A[i + n]; // A[i] = A[i] ^ A[i+n] = A[i] ^ A[i] ^ A[i+n] = A[i+n]
    }
}
int main()
{
    int A[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int m = 5, n = 5;
    swap(A, m, n);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
*/