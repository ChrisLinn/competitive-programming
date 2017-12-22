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
                for (int j = 1; j <= A[i] && (i+j) < A.size(); ++j) {
                    res[i+j] = true;
                }
            }
        }
        
        return res[A.size()-1];
    }
};

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int reachable = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + A[i]);
        }

        return true;
    }
};



class Solution2 {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int sz = A.size();
        
        int reachable = A[0];
        for(int i=0; i<=reachable; ++i){
            reachable = max(reachable, A[i] + i);
            if (reachable >= sz-1)
                return true;
        }
        return false;
    }
};
