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
    int findBottomLeftValue(TreeNode* root) {
        //Note: You may assume the tree (i.e., the given root node) is not NULL.

        int max_d = getMaxDepth(root);

        queue<TreeNode *> q;
        q.push(root); 
        int d = 1;
        TreeNode *cur;
        while(d<max_d) {
            cur = q.front();
            
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }

            q.pop();
            d++;
        }

        while(1) {
            cur = q.front();
            if(cur->left) {
                return cur->left->val;
            }
            if(cur->right) {
                return cur->right->val;
            }
            q.pop();
        }

    }

private:
    int getMaxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        } else {
            int l = getMaxDepth(root->left);
            int r = getMaxDepth(root->right);
            return 1 + ((l>=r)?l:r);
        }
    }
};