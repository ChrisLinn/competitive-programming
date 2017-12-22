class Solution {
public:
    /*
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        if (s3.length() !=  (s1.length() + s2.length())) {
            return false;
        } else {
            string s1s2 = s1 + s2;
            string s2s1 = s2 + s1;

            if (s3==s1+s2 || s3==s2+s1) {
                return true;
            } else {
                for (int i = 1; i<min(s1.length(), s2.length()); ++i) {
                    string s1l = s1.substr(0,i);
                    string s1r = s1.substr(i, s1.length()-i);
                    string s2l = s2.substr(0,i);
                    string s2r = s2.substr(i, s2.length()-i);
                    string s3l = s3.substr(0,2*i);
                    string s3r = s3.substr(2*i, s3.length()-2*i);

                    if (isInterleave(s1l, s2l, s3l)
                        && isInterleave(s1r, s2r, s3r)) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
};