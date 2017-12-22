class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        // write your code here
        int res = 0;
        bool hasOdd = false;

        vector<int> count = vector<int>(128, 0);

        for (auto c: s) {
            ++count[c];
        }

        for (auto c: count) {
            res += (c/2)*2;
            hasOdd = hasOdd || c%2;
        }


        // unordered_map<char, int> char_counter;
        // ...
        // for (auto itr = char_counter.begin(); itr != char_counter.end(); ++itr)
        // {
        // ...
        // }

        return res + hasOdd;
    }
};