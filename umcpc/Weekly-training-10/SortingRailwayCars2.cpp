/**/


/*
另开一个数组，记录a[i]所在位置i，即b[a[i]]=i；然后每次比较b[j]和b[j-1]，
如果b[j]>b[j-1]说明编号j可以插入当前上升子序列，否则的话，当前子序列结束，比较这个子序列的
长度和已经计算过的子序列长度，保留较大的一个。
*/


#include <stdio.h>
#include <string.h>
#define maxn 100010
int a[maxn],n,b[maxn],len,ans;
int main()
{
    //freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);
    while (~scanf("%d", &n))
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%d", &a[i]);
            b[a[i]]=i;
        }
        len = 1;
        ans = 0;

        //12534
        //12453
        for (int i = 2;i <= n;i++)
        {
            if (b[i] > b[i - 1]) len ++ ;
            else
            {
                ans = ans > len ? ans : len;
                len = 1;
            }
        }
        ans = ans > len ? ans : len;
        printf("%d\n", n - ans);
    }
    return 0;
}