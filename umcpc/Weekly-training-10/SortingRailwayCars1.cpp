/*最长差一上升子序列version*/
/*
首先跑最长上升子序列是错的
比如 1 2 4 5 3
最长上升子序列答案跑出来是1
但实际上答案是2
所以只能跑严格只比之前大1的子序列就好了

用另外一个数组储存最长序列长度，
只要在输入得时候判断比它小一的元素是否在其左边，
是，则其下标为左边小一的元素下标加一，否，则为一
*/

#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
#include <cmath>

using namespace std;  

const int N=100000+10;  
int a[N],b[N];  

int main()  
{  
    int n,i; 
    //When scanf() will encounter EOF having value -1, then the statement will
    // be like this :
    //         while (~( -1)) 
    //which converts to while (0) and the loop will break. 
    //This is a horrible way to check if a value is different from -1.
    // ~x returns the bitwise negation of x. So having in mind the complimentary
    // code used for negative numbers(on most compilers by the way so this approach 
    //is not even very portable) -1 is represented by a sequence of 1-s and
    // thus ~(-1) will produce a zero.
    while(~scanf("%d",&n))  
    {  
        memset(b,0,sizeof(b));  
        for(i=1; i<=n; i++)  
        {  
            scanf("%d",&a[i]); 
            //子序列的最后一个元素
            //b[ i ] 表示到 i 时最长子序列的长度。
            b[a[i]]=b[a[i]-1]+1;  
        }  
        // actually we only care about the max in b, we can do sort array b
        //, and then use b[n]
        // or we can keep update the max in the for loop above.
        sort(b+1,b+n+1);
        if(b[n]==n)  
            printf("0\n");  
        else  
            printf("%d\n",n-b[n]);  
    }  
    return 0;  
} 