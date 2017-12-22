class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        nth_element (nums.begin(), nums.begin() + n, nums.end(), 
                [](const int a, const int b) -> bool
                { 
                    return a > b; 
                }
            );
        // or nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        for (int a: nums) {
            cout<<a;
        }
        return nums[n-1];
    }
    
    int kthLargestElement4(int n, vector<int> &nums) {
        // write your code here
        nth_element (nums.begin(), nums.begin() + n, nums.end(), 
                [](const int a, const int b) -> bool
                { 
                    return a > b; 
                }
            );
        for (int a: nums) {
            cout<<a;
        }
        return nums[n-1];
    }

    int kthLargestElement3(int n, vector<int> &nums) {
        // write your code here
        partial_sort (nums.begin(), nums.begin() + n, nums.end(), 
                [](const int a, const int b) -> bool
                { 
                    return a > b; 
                }
            );
        for (int a: nums) {
            cout<<a;
        }
        return nums[n-1];
    }

    int kthLargestElement2(int n, vector<int> &nums) {
        // write your code here        
        // partial_sort (nums.begin(), nums.begin() + nums.size() - n + 1, nums.end());
        partial_sort (nums.begin(), nums.end() - n + 1, nums.end());
        for (int a: nums) {
            cout<<a;
        }
        return nums[nums.size() - n];
    }

    int kthLargestElement1(int n, vector<int> &nums) {
        // write your code here        
        sort(nums.begin(), nums.end());
        return nums[nums.size() - n];
    }
};