/*
 * @Descripttion: 行列式
 * @Author: zkb
 * @Date: 2023-01-03 09:25:31
 * @LastEditors: zkb
 * @LastEditTime: 2023-01-06 10:59:21
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct
{
    int arr[10];
    int rows;
} Array2D;

void complementMinor(int n, double a[][n], int i, int j, double b[n - 1][n - 1])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row > i && col < j)
            {
                b[row - 1][col] = a[row][col];
            }
            else if (col > j && row < i)
            {
                b[row][col - 1] = a[row][col];
            }
            else if (col > j && row > i)
            {
                b[row - 1][col - 1] = a[row][col];
            }
            else
            {
                if (row < n - 1 && col < n - 1)
                {
                    b[row][col] = a[row][col];
                }
            }
        }
    }
    // return det;
    //*b = det;
}
double determinant(int n, double a[][n])
{

    if (n == 2)
    {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else
    {
        double result = 0;

        for (int i = 0; i < n; i++)
        {
            double minor[n - 1][n - 1];
            complementMinor(n, a, i, 0, minor);
            // printf("%.1f\n", determinant(n - 1, minor));
            result += pow(-1, i) * determinant(n - 1, minor);
            printf("%.1f\n", result);
        }
        return result;
    }
}
void toString(int n, double a[][n])
{
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            printf("%5.1f", a[i][j]);
        }
        printf("|\n");
    }
}
int main()
{
    int n = 4;
    double a[4][4] = {
        1, 1, -1, 2,
        -1, -1, -4, 1,
        2, 4, -6, 1,
        1, 2, 4, 2};

    toString(n, a);

    // int b[3][3];
    // complementMinor(4, a, 3, 3, &b);
    // toString(3, b);
    printf("%f\n", determinant(n, a));
    return 0;
}