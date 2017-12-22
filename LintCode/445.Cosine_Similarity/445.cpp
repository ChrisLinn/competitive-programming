class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Cosine similarity
     */
    double cosineSimilarity(vector<int> &A, vector<int> &B) {
        // write your code here

        double numerator, denominator_a, denominator_b;
        numerator = 0;
        denominator_a = 0;
        denominator_b = 0;

        if (A.size() != B.size()) {
            return 2.0000;
        }

        if (!A.size()) {
            return 2.0000;
        }

        // one loop
        for (std::vector<int>::iterator it_a = A.begin(), it_b = B.begin();
            it_a != A.end();
            ++it_a, ++it_b) {
            numerator += (*it_a)*(*it_b);
            denominator_a += (*it_a)*(*it_a);
            denominator_b += (*it_b)*(*it_b);
        }

        if (!denominator_a || !denominator_b) {
            return 2.0000;
        }

        // denominator_a = pow(denominator_a, 0.5);
        denominator_a = sqrt(denominator_a);
        denominator_b = sqrt(denominator_b);

        return numerator/denominator_a/denominator_b;
    }
};