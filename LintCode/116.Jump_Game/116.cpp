class Solution1 {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        
        vector<bool> res;
        res.resize(A.size(), false);
        res[0] = true;
        
        for (int i = 0; i < A.size(); ++i) {
            if (res[i]) {
                for (int j = 1; j <= A[i]; ++j) {
                    res[i+j] = true;
                }
            }
        }
        
        return res[A.size()-1];
    }
};