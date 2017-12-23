class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        }

        vector<int> ways(3);
        ways[0] = k;
        ways[1] = (k - 1) * ways[0] + k;
        for (int i = 2; i < n; ++i) {
            ways[i % 3] = (k - 1) * (ways[(i - 1) % 3] + ways[(i - 2) % 3]);
        }
        return ways[(n - 1) % 3];
    }
};


class Solution1 {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n <= 0 || k <= 0)
            return 0;
        if (n <= 2)
            return pow(k, n);
        
        int same = k, diff = k*(k-1), res = k*k;
        for (int i = 3; i <= n; i++) {
            //at i, the num of last two same equal to the num of last two diff in previous step
            same = diff; 
            //at i, the num of last two different equal to the num of results in previous step multiply (k - 1)
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
    }
};


class Solution2
{
public:
    int numWays(int n, int k) 
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k*k;
        int pre = k;
        int now = k*k;
        for (int i = 3; i <= n; i++)
        {
            int tmp = now;
            now = (pre+now) * (k-1);
            pre = tmp;
        }
        return now;
    }
};