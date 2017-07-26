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
    string tree2str(TreeNode* t) {
        string left = "";
        string right = "";

        if (!t) {
            return "";
        }
        else if (!t->left && !t->right) {
        }
        else if (t->right) {
            left = "(" + tree2str(t->left) + ")";
            right = "(" + tree2str(t->right) + ")";
        }
        else if (t->left && !t->right) {
            left = "(" + tree2str(t->left) + ")";
        }

        return std::to_string(t->val) +
                left + 
                right;
    }
};