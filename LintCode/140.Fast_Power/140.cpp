class Solution {
public:
    /*
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
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
        if(n&1) // missing one because of '/'
            res = (res*a)%b;
        return res;
    }
};