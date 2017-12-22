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

        // const double invalid = 2.0;
        // ...
        // return A_dot_A && B_dot_B ?
        //            A_dot_B / sqrt(A_dot_A) / sqrt(B_dot_B) :
        //            invalid;
    }
};




// #include <algorithm>
// #include <cmath>
// using namespace std;

// typedef vector<int> VI;

// class Solution {
// public:
//     /**
//      * @param A: An integer array.
//      * @param B: An integer array.
//      * @return: Cosine similarity.
//      */
//     double cosineSimilarity(VI A, VI B) {
//         double normA = sqrt(innerProduct(A, A));
//         double normB = sqrt(innerProduct(B, B));
//         if (fabs(normA) < EPS || fabs(normB) < EPS) {
//             return INVALID_VALUE;
//         }
        
//         return innerProduct(A, B) / (normA * normB);
//     }
// protected:
//     double EPS = 1e-7;
//     double INVALID_VALUE = 2.0;
    
//     double innerProduct(const VI &a, const VI &b) {
//         int n = min(a.size(), b.size());
//         double sum = 0.0;
//         for (int i = 0; i < n; ++i) {
//             sum += 1.0 * a[i] * b[i];
//         }
//         return sum;
//     }
// };