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

int main() {
    int num = -1;
    
    Solution sol;
    int res = sol.countOnes(num);
    cout<<res<<endl;

    return 0;
}

