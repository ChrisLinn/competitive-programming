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

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int newLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            //跳到一个新的，或下一个是新的
            if (i > 0 && i < nums.size()-1 && nums[i] == nums[i-1] && nums[i] == nums[i+1]) {
                continue;
            }

            nums[newLen++] = nums[i];
        }

        return newLen;
    }
};