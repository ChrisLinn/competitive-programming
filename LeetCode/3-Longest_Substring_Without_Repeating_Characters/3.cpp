class Solution {
public:
    int lengthOfLongestSubstring2(string s)  {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX]; // 记录字符上次出现过的位置
        int start = 0; // 记录当前子串的起始位置
        fill(last, last + ASCII_MAX, -1); // 0也是有效位置,因此初始化为-1
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= start) {
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return  max((int)s.size() - start, max_len); // 别忘了最后一次,例如"abcd"
    }



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