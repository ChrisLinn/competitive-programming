/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        SegmentTreeNode* res = new SegmentTreeNode(start, end);
        
        if (start != end) {
            res->left = build(start, (start + end) / 2);
            res->right = build((start + end) / 2 + 1, end);
        }
        
        return res;
    }
};