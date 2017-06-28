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
    vector<int> modes;
    
    vector<int> nodes;
    
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        sort(nodes.begin(), nodes.end());
        return nodes;
    }
    
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->left);
            nodes.push_back(root->val);
            traverse(root->right);
        }
    }
};