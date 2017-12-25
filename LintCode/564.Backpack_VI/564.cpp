class Solution {
public:
    /*
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */

    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        if (target <= 0)
            return 0;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums)
                if (num <= i)
                    dp[i] += dp[i - num];
                else
                    break;
        }
        return dp[target];
    }
};
