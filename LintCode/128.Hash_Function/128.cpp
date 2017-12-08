#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /*
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
        long long int hashcode = 0;
    
        // int len = key.length();
        // for (int i = 0; i < len; ++i) {
        //     hashcode = (hashcode * 33 % HASH_SIZE + key[i] % HASH_SIZE) % HASH_SIZE;
        // }
    
        for (const auto& c : key) {
            hashcode = (hashcode * 33 % HASH_SIZE + c % HASH_SIZE) % HASH_SIZE;
        }
        
        return hashcode;
    }
};

int main() {
    string str = "abcd";
    int HASH_SIZE = 100;
    
    Solution sol;
    int hash = sol.hashCode(str, HASH_SIZE);
    cout<<hash<<endl;

    return 0;
}

