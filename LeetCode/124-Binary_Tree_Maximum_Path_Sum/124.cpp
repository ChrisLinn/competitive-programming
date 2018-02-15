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
    int maxPathSum(TreeNode* root) {
        this->maxSum = INT_MIN;

        if(root) {
            dfs(root);
        }

        return this->maxSum;
    }

private:
    int maxSum;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
        int sub = max(left, right);

        this->maxSum = max(this->maxSum, left + right + node->val); //!

        return sub + node->val;
    }
};
