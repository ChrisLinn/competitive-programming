class Solution {
public:
    /*
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */

    // Time:  O(logn)
    // Space: O(logn)
    // Recursive solution.
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n == 0)
            return 1%b;
        if(n == 1)
            return a%b;
        //(a*b)%x = ((a%x) * (b%x)) %x
        long long res = 0;
        res = fastPower(a, b, n/2);
        res*=res;
        res%=b;
        if (n & 1) { // missing one because of '/'
        // if (n % 2 == 0) {
            res = (res*a)%b;
        }
        return res;
    }
};



class Solution1 {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    
    // Time:  O(logn)
    // Space: O(1)
    // Iterative solution.
    int fastPower(int a, int b, int n) {
        long long result = 1;
        long long x = a % b;
        while (n > 0) {
            if (n & 1) {
                result = result * x % b;
            }
            n >>= 1;
            x = x * x % b;
        }
        return result % b;
    }
};