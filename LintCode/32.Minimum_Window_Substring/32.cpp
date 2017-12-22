class Solution {
public:
    /*
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        int i, j, res_i, res_j;
        int covered = 0;
        std::set<char> alreadyCover;

        for (i = 0, j = 0, res_i = 0, res_j = source.length(); i < source.length(); ) {

            if (target.find(source[j]) != std::string::npos) { // source[j] in target
                if (alreadyCover.find(source[j]) == alreadyCover.end()) { // !alreadyCover(source[j])
                    ++covered;
                    alreadyCover.emplace(source[j]);
                } else { // alreadyCover(source[j])
                    if (source[j] != source[i]) {
                        i = j;
                        covered = 0;
                        alreadyCover.clear();
                    } else {
                        while (alreadyCover.find(source[++i]) == alreadyCover.end()) { // !alreadyCover(source[++i])
                        }
                    }
                }
            }

            if (j < source.length()) {
                ++j;
            }

            if (covered == target.length()) {
                if ((j - i) < (res_j - res_i)) {
                    res_i = i;
                    res_j = j;
                }
            }

            if (j == source.length()) {
                ++i;
            }
        }

        if (covered == target.length()) {
            return source.substr(res_i, res_j);
        } else {
            return "";
        }
    }
};
