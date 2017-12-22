class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Cosine similarity
     */
    double cosineSimilarity(vector<int> &A, vector<int> &B) {
        // write your code here

        double numerator, denominator1, denominator2, denominator;
        numerator = 0;
        denominator1 = 0;
        denominator2 = 0;
        denominator = 0;

        if (A.size() != B.size()) {
            return 2.0000;
        }

        for (std::vector<int>::iterator it_a = A.begin(), it_b = B.begin();
            it_a != A.end();
            ++it_a, ++it_b) {
            numerator += (*it_a)*(*it_b);
        }

        for (auto a: A) {
            denominator1 += a*a;
        }
        if (!denominator1) {
            return 2.0000;
        }

        for (auto b: B) {
            denominator2 += b*b;
        }
        if (!denominator2) {
            return 2.0000;
        }

        denominator = pow(denominator1*denominator2, 0.5);

        return numerator/denominator;
    }
};