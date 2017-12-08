/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> q;

        if (root) {
            vector<int> self;
            self.push_back(root->val);
            q.push_back(self);
            
            vector<vector<int>> left = levelOrder(root->left);
            vector<vector<int>> right = levelOrder(root->right);


            for (int depth = 0; depth < left.size(); ++depth) {
                q.push_back(left[depth]);
            }

            for (int depth = 0; depth < right.size(); ++depth) {
                if (depth < left.size()) {
                    for (int i = 0; i < right[depth].size(); ++i) {
                        q[depth + 1].push_back(right[depth][i]);
                    }
                } else {
                    q.push_back(right[depth]);
                }
            }
        }

        return q;
    }
};