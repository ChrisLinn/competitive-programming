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
        int exp = 0;
        int isNeg = 0;

        if (num < 0) {
            num = INT_MAX + num + 1;
            isNeg = 1;
        }

        while (num > 0) {
            if (num % 2 != 0) {
                ++res;
            }
            num /= 2;
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

