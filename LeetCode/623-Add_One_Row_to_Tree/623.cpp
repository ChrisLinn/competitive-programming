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

        if(d == 1) {
            newTreeRoot = new TreeNode(v);
            newTreeRoot->left = root;
        } else {
            bfs(root, v, d);
        }

        return root = newTreeRoot;
    }

    void bfs(TreeNode* root, int v, int d) {

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