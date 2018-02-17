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
    int kthSmallest(TreeNode* root, int k) {
        this->target = k;
        this->cur = 0;
        inOrder(root);
        return this->res;
    }

private:
    int target;
    int cur;
    int res;
    void inOrder(TreeNode* node) {

        if(!node) {
            return;
        } else {
            if(node->left) {
                inOrder(node->left);
            }

            ++cur;
            if(this->cur == this->target) {
                this->res = node->val;
            }

            if(node->right) {
                inOrder(node->right);
            }

        }
    } 
};