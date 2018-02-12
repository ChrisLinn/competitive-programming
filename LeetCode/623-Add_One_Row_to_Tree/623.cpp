/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* newTreeRoot = root;

        if(d > 1) {
            dfs(root, v, d);
        } else {
            newTreeRoot = new TreeNode(v);
            newTreeRoot->left = root;
        }

        return root = newTreeRoot;
    }

    void dfs(TreeNode* root, int v, int d) {

        if(d > 2) {
            if(root->left) {
                dfs(root->left, v, d-1);
            }
            if(root->right) {
                dfs(root->right, v, d-1);
            }
        } else if(d == 2) {
            TreeNode* newLeft = new TreeNode(v);
            TreeNode* newRight = new TreeNode(v);

            if(root->left) {
                newLeft->left = root->left;
            }
            if(root->right) {
                newRight->right = root->right;
            }

            root->left = newLeft;
            root->right = newRight;
        }
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(333);

    root->left = new TreeNode(123);
    root->right = new TreeNode(321);

    Solution sol;
    root = sol.addOneRow(root, 2, 1);

    cout << root->val << endl;
    cout << root->left->val << endl;
    return 0;
}