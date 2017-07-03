class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> current;
        current.push_back("");
        return dfs(current,0,0,n);
    }
};

vector<string> dfs(vector<string> current,int x,int y,int n){
    vector<string> level_result;

    vector<string> down_result = down(current,x,y);
    if (down_result.size()!=0) {
        level_result.insert(level_result.end(), 
                            down_result.begin(), down_result.end());
    }

    vector<string> right_result = right(current,x,y);
    if (right_result.size()!=0) {
        level_result.insert(level_result.end(), 
                            right_result.begin(), right_result.end());
    }

    return level_result;
}

vector<string> down(vector<string> current,int x,int y,int n){
    // for string in current {
    //     string +'(';
    // }
    x++;
    if (x>n||Y>n||(x+y)>2*n) {
        return current.clear();
    } else if ((x+y)==2*n) {
        return current;
    }
    else {
        return dfs(current,x,y,n);
    }
}

vector<string> right(vector<string> current,int x,int y,int n){
    // for string in current {
    //     string +')';
    // }
    y++;
    if (x>n||Y>n||(x+y)>2*n) {
        return current.clear();
    } else if ((x+y)==2*n) {
        return current;
    }
    else {
        return dfs(current,x,y,n);
    }
}