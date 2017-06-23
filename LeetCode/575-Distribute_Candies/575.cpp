class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds;
        for (int kind : candies) {
            kinds.insert(kind);
        }
        return min(kinds.size(), candies.size() / 2);
    }
};

/*
+ min
+ size
+ unordered_set
    + insert()
    + constructor using range iterator
+ sort vector
    + compare with [i-1] and decide whether to increase cnt
+ bitset
*/