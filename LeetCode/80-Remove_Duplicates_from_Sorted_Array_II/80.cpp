class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        // i 为新读位
        // newLen 为新待填位
        int newLen = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[newLen-2]) {
                nums[newLen++] = nums[i];
            }
        }

        return newLen;
    }
};