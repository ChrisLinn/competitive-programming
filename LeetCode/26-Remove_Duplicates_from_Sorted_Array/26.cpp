class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int newLen = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[newLen-1]) {
                nums[newLen++] = nums[i];
            }
        }   
        return newLen;   
    }
};