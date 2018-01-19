// 如果允许 O(nlogn) 的复杂度，那么可以先排序，可是本题要求 O(n)。
// 由于序列里的元素是无序的，又要求 O(n)，首先要想到用哈希表。
// 用一个哈希表存储所有出现过的元素，对每个元素，以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长度。

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset;

        for (auto num:nums) {
            myset.insert(num);
        }

        int longest = 0;
        
        for (auto num:nums) {
            int length = 1;

            for (int i = num-1; myset.find(i)!=myset.end(); --i) {
                myset.erase(i);
                ++length;
            }
            for (int i = num+1; myset.find(i)!=myset.end(); ++i) {
                myset.erase(i);
                ++length;
            }
            longest = max(longest, length);
        }

        return longest;
    }
};