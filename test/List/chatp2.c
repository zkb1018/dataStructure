#include <stdio.h>
/**
 * @msg: 一个长为N的数组A[1....N] 给定整数X 查找数组中两个之和为X的整数对
 *        要求时间复杂度不超过O(nlog2n)
 * @return {*}
 */

void quickSort(int *a, int left, int right);
int sortOnce(int *a, int left, int right);
void getDoubleBySum(int *a, int n, int x);
int main()
{
    int A[10] = {6, 2, 7, 3, 5, 2, 7, 4, 8, 2};
    getDoubleBySum(A, 10, 9);
    return 0;
}
void quickSort(int *a, int left, int right)
{ // 快速排序时间复杂度O(nlog2n)
    if (left < right)
    {
        int key = sortOnce(a, left, right);
        quickSort(a, left, key - 1);
        quickSort(a, key + 1, right);
    }
}
int sortOnce(int *a, int left, int right)
{
    int keyIndex = left;
    int key = a[left];
    while (left < right)
    {
        while (left < right && key < a[right])
        {
            right--;
        }
        a[left] = a[right];
        while (left < right && key >= a[left])
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = key;
    return left;
}

void getDoubleBySum(int *a, int n, int x)
{
    quickSort(a, 0, n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] > x)
        {
            j--;
        }
        else if (a[i] + a[j] < x)
        {
            i++;
        }
        else
        {
            printf("%d~%d\n", a[i], a[j]);
            i++;
            j--;
        }
    }
}