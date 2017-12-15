class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPackImp(int m, vector<int> A) {
        // write your code here
        int mx = 0;
        int nItems = A.size();
        int size = m;

        // canFillIn[i%2][j]
        // can fulfill the backpack with size j
        // using 2 column to store the info for last turn (first i-1)
        bool canFillIn[2][size+1];
        memset(canFillIn, 0 , 2*(size+1)*sizeof(bool));
        // or vector<vector<bool>> canFillIn = vector<vector<bool>>(2, vector<bool>(m+1, false));
        // or vector<vector<bool>> canFillIn(2, vector<bool>(m+1, false));

        for (int i = 0; i < 2; ++i) {
            canFillIn[i][0] = true;
        }

        for (int i = 1; i < nItems+1; ++i) {
            for (int j = 0; j < size+1; ++j) {
                // if using first i-1 can fulfill the backpack, then the first i would also work
                canFillIn[i%2][j] = canFillIn[(i-1)%2][j];

                // 0-based indexing for A!
                if (A[i-1] <= j) {
                    canFillIn[i%2][j] = canFillIn[i%2][j] || canFillIn[(i-1)%2][j - A[i-1]];
                }

                if (canFillIn[i%2][j]) {
                    mx = max(mx, j);
                }
            }
        }        

        return mx;
    }

    int backPack(int m, vector<int> A) {
        // write your code here
        int mx = 0;
        int nItems = A.size();
        int size = m;

        bool canFillIn[size+1];
        memset(canFillIn, 0 , (size+1)*sizeof(bool)); // or fill(canFillIn, canFillIn + size + 1, false);
        // or vector<bool> canFillIn(size+1, false);
        // or vector<bool> canFillIn; canFillIn.resize(size+1, false);
        // or
        // `bool* canFillIn = new bool[size+1];`
        // but don't forget to `delete[] canFillIn` at the end!!!

        canFillIn[0] = true;

        // using first i+1 items 
        for (int i = 0; i < nItems; ++i) {
            // backward so no need to store for the last turn
            for (int j = size; j>=A[i]; --j) {
                canFillIn[j] = canFillIn[j] || canFillIn[j - A[i]];
            }
        }

        for (mx = size; !canFillIn[mx]; --mx) {
        }

        return mx;
    }
};
