class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> current;
        current.push_back("");
        dfs(current,0,0);
    }
};

vector<string> dfs(current,x,y){
    vector<string> level_result;

    vector<string> down_result = down(current,x,y);
    if (down_result.size()!=0) {
        level_result.
    }

    vector<string> down_result = right(current,x,y);
    if (down_result.size()!=0) {
        level_result.
    }

    return level_result;
}

vector<string> down(current,x,y){
    for string in current {
        string +'(';
    }
    x++;
    if (x>n||Y>n||(x+y)>2*n) {return current.clear()}
    else if ((x+y)==2*n) return current;
    else return dfs(current,x,y)
}

vector<string> right(current,x,y){
    for string in current {
        string +')';
    }
    y++;
    if (x>n||Y>n||(x+y)>2*n) {return current.clear()}
    else if ((x+y)==2*n) return current;
    else return dfs(current,x,y);
}