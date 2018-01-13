class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int sz = prices.size();
        int mx = 0;
        for(int i=1;i<sz;i++){
            if(prices[i]>prices[i-1]){
                mx+=(prices[i]-prices[i-1]);
            }
        }
        return mx;
    }
};