class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
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

    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        map<char,int> map;
        for (int j = 0, i = 0; j < n; j++) {
            if (map.find(s[j]) != map.end()) {
                i = map[s[j]] > i ? map[s[j]] : i;
            }
            ans = ans > j-i+1 ? ans: j-i+1;
            map[s[j]] = j + 1;
        }        
        return ans;
    }
};