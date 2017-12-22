/*
Given a binary tree, determine if it is height-balanced.
 
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
Example
Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}
 
A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.
*/
 
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
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        } else {
            int l = calcDepth(root->left, 1);
            int r = calcDepth(root->right, 1);
            return (abs( l - r ) <= 1)
                    && isBalanced(root->left)
                    && isBalanced(root->right);
        }
    }

    int calcDepth(TreeNode *node, int d) {
        if (node) {
            int l, r;
            l = calcDepth(node->left, d+1);
            r = calcDepth(node->right, d+1); 
            return max(l, r);
        } else {
            return d;
        }
    }


    int getHeight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
};


class Solution1 
{
public:
    bool isBalanced(TreeNode *root) 
    {
        if(root==NULL)
            return true;
        if(abs(getHeight(root->left)-getHeight(root->right))>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int getHeight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
};


class Solution2 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int h;
        return isBalHelper(root, h);
    }
    
    bool isBalHelper(TreeNode *root, int &h){
        if(!root){
            h = 1;
            return true;
        }
        int l_h = 0;
        int r_h = 0;
        bool l = isBalHelper(root->left, l_h);
        bool r = isBalHelper(root->right, r_h);
        h = max(l_h, r_h) + 1;
        return l&&r&&abs(l_h-r_h)<=1;
    }
};


class Solution3 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return isBalancedRecu(root).first;
    }

    pair<bool, int> isBalancedRecu(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }

        pair<bool, int> left = isBalancedRecu(root->left);
        pair<bool, int> right =  isBalancedRecu(root->right);

        if (left.first && right.first && abs(left.second - right.second) <= 1) {
            return {true, max(left.second, right.second) + 1};
        }
        else {
            return {false, 0};
        }
    }
};


