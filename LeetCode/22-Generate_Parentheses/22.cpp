class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> current;
        current.push_back("");
        dfs(current,0,0);
    }
};