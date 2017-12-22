class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int mx = 0;
        int nItems = A.size();
        int size = m;

        // canFulfill[i%2][j]
        // can fulfill the backpack with size j
        // using 2 column to store the info for last turn (first i-1)
        bool canFulfill[2][size+1];
        memset(canFulfill, 0 , 2*(size+1)*sizeof(bool));
        // or vector<vector<bool>> canFulfill = vector<vector<bool>>(2, vector<bool>(m+1, false));
        // or vector<vector<bool>> canFulfill(2, vector<bool>(m+1, false));

        for (int i = 0; i < 2; ++i) {
            canFulfill[i][0] = true;
        }

        for (int i = 1; i < nItems+1; ++i) {
            for (int j = 0; j < size+1; ++j) {
                // if using first i-1 can fulfill the backpack, then the first i would also work
                // not using the i th
                canFulfill[i%2][j] = canFulfill[(i-1)%2][j];

                // 0-based indexing for A!
                if (A[i-1] <= j) {
                    canFulfill[i%2][j] = canFulfill[i%2][j] || canFulfill[(i-1)%2][j - A[i-1]]; // using the i th
                }

                if (canFulfill[i%2][j]) {
                    mx = max(mx, j);
                }
            }
        }        

        return mx;
    }

    int backPackImp(int m, vector<int> A) {
        // write your code here
        int mx = 0;
        int nItems = A.size();
        int size = m;

        bool canFulfill[size+1];
        memset(canFulfill, 0 , (size+1)*sizeof(bool)); // or fill(canFulfill, canFulfill + size + 1, false);
        // or vector<bool> canFulfill(size+1, false);
        // or vector<bool> canFulfill; canFulfill.resize(size+1, false);
        // or
        // `bool* canFulfill = new bool[size+1];`
        // but don't forget to `delete[] canFulfill` at the end!!!

        canFulfill[0] = true;

        // using first i+1 items 
        for (int i = 0; i < nItems; ++i) {
            // backward so no need to store for the last turn
            for (int j = size; j>=A[i]; --j) {
                canFulfill[j] = canFulfill[j] /* not using the i th */ || canFulfill[j - A[i]] /* using the i th */;
            }
        }

        for (mx = size; !canFulfill[mx]; --mx) {
        }

        return mx;
    }
};
