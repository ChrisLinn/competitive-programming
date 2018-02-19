/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> freqSum;
        
        if(root) {
            dfs(root);

            sort(this->sums.begin(), this->sums.end());

            int freq = 0;
            int maxFreq = 0;
            this->sums.push_back(this->sums.back() - 1);

            for(vector<int>::iterator it = this->sums.begin()+1;
                                    it != this->sums.end(); ++it) {
                ++freq;
                
                if (*it != *(it-1)) {
                    if(freq > maxFreq) {
                        maxFreq = freq;
                        freqSum.clear();
                        freqSum.push_back(*(it-1));
                    } else if(freq == maxFreq) {
                        freqSum.push_back(*(it-1));                        
                    }

                    freq = 0;
                }
            }
        }

        return freqSum;
    }

private:
    vector<int> sums;

    int dfs(TreeNode* node){
        int sum;

        // if(!node) {
        //    sum = 0;
        // } else {
            sum = node->val;

            if(node->left) {
                sum += dfs(node->left);
            }
            if(node->right) {
                sum += dfs(node->right);
            }

            this->sums.push_back(sum);
        // }

        return sum;
    }
};
