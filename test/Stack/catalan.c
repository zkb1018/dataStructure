#include <stdio.h>
#include <stdlib.h>
/**
 * @msg: n个不同元素入栈 出栈顺序共有几种
 *       (1/(n+1))*Cn-2n
 * @return {*}
 */

int catalan(int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (n == 2)
        return 2;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += catalan(i) * catalan(n - i - 1);
    }
    return total;
}

int main()
{
    printf("%d", catalan(4));
    return 0;
}