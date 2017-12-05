class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> myset;
        int ans = 0, i = 0, j = 0;

        while (i < len && j < len) {
            unordered_set<char>::const_iterator got = myset.find(s[j]);

            if ( got == myset.end() ){
                myset.insert(s[j++]);
                ans = ans>(j-i)?ans:(j-i);
            }
            else {
                myset.erase(s[i++]);
            }            
        }           

        return ans;
    }
};