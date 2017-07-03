class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=0) {
                nums[j++] = nums[i];
            }
        }

        for (;j<nums.size();j++) {
            nums[j] = 0;
        }
    }

    void moveZeroes2(vector<int>& nums) {
        int scan_pos = 0, new_pos = 0;

        for (; scan_pos < nums.size(); scan_pos++) {
            if (nums[scan_pos] != 0) {
                swap(nums[scan_pos], nums[new_pos++]);
            }
        }
    }

    void moveZeroes3(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
    }
};