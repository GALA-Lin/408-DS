#include "seq_list_utils.h"
/*
  给定三个序列A、B、C，长度均为n，且均为无重复元素的递增序列，请设计一个时间上尽可能高效的算法，
  逐行输出同时存在于这三个序列中的所有元素。
  例如，数组A为{1,2,3}，数组B 为{2,3,4}，数组C为{-1,0,2}，则输出 2。
*/
void print_common_elements(int A[], int B[], int C[], int n)
{
    /*
      使用三个下标变量从小到大遍历数组。当三个下标变量指向的元素相等时，输出并向前推进指针，
      否则移动指向最小元素的下标变量，直到某个下标变量移出数组范围，即可停止。
    */
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            cout << A[i] << endl;
            i++;
            j++;
            k++;
        }
        else
        {
            int minNum = min(A[i], min(B[j], C[k]));
            if (A[i] == minNum)
                i++;
            else if (B[j] == minNum)
                j++;
            else if (C[k] == minNum)
                k++;
        }
    }
}
int main()
{
    int n = 3;
    int A[] = {1, 2, 3}, B[] = {0, 1, 3}, C[] = {-1, 1, 3};
    print_common_elements(A, B, C, n);
    return 0;
}
