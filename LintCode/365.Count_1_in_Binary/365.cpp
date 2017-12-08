#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int res = 0;
        
        // 和 res += num & 0x1 差不多，方向不同而已
        // for (int exp = 0, base = 1; exp < 32; ++exp, base<<1) {
        //     if (num & base) {
        //         ++res;
        //     }
        // }
        
        for (int exp = 0; exp < 32; ++exp) {
            // //感觉对负数不够直观
            // if (num % 2) { 
            //     ++res;
            // }
            // // num /= 2 不行
            // num >> 1;

            //还是这个好一些
            res += num & 0x1;
            num>>1;
        }

        
        return res;
    }
};

class Solution1 {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int res = 0;
        int isNeg = 0;

        if (num < 0) {
            num = INT_MAX + num + 1;
            isNeg = 1;
        }

        while (num > 0) {
            // if (num % 2 != 0) {
            if (num & 1 == 1) {
                ++res;
            }
            num >>= 1;
            // num = num>>1;
            // num /= 2;
        }

        return res + isNeg;
    }
};



class Solution2 {
public:
    int countOnes(int num) 
    {
        int counter=0;
        for(int i=0;i<32;++i)
        {
            counter+=(num%2+2)%2;
            num>>=1;
        }
        return counter;
    }
};



class Solution3 {
// Time:  O(logn) = O(32)
// Space: O(1)
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int count = 0;


        // 原理:
        // https://stackoverflow.com/questions/4678333/n-n-1-what-does-this-expression-do
        //
        // 如果是 2 的幂,那么正好只有 1 个 1, 做完之后变 0;
        //
        // 如果不是 2 的幂, 那么就会是类似 `0..010..010..`, 是好几个 2 不同幂之和, 
        // 通过 `n & (n-1)` 能把最小的那个幂消去.

        for (; num; num &= num - 1) {
            ++count;
        }

        // while (num > 0) {
        //     num = num & num - 1;
        //     ++c;
        // }

        return count;
    }
};



int main() {
    int num = -1;
    
    Solution sol;
    int res = sol.countOnes(num);
    cout<<res<<endl;

    return 0;
}

