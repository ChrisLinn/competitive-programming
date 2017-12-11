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
    vector<vector<int>> levelOrder1(TreeNode * root) {
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



    vector<vector<int>> levelOrder2(TreeNode *root) {
        // write your code here
        queue<TreeNode *> q;
        vector<vector<int>> res;
        vector<int> level;
        if(!root)
            return res;
        
        q.push(root); // emplace() will be better, save the temp var ?
        q.push(NULL); // use NULL to denote the end of each level
        
        while(q.size()){  
        // or  while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t){
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }else{
                res.push_back(level);
                level.clear();
                // or
                // res.push_back(move(level));
                
                if(q.size())
                    q.push(NULL);
            }
        }
        return res;
    }


    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if(!root)
            return result;

        que.emplace(root);
        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto *front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr) {
                    que.emplace(front->left);
                }
                if (front->right != nullptr) {
                    que.emplace(front->right);
                }
            }
            result.emplace_back(move(level));
        }

        return result;
    }
};