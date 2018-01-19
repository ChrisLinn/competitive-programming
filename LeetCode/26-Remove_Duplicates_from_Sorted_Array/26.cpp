class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // i 为新读位
        // newLen 为新待填位
        int newLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[newLen-1]) {
                nums[newLen++] = nums[i];
            }
        }   
        return newLen;   
    }
};

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        // write your code here
        int count = 0;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }
};