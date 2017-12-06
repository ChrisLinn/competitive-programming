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
        int hashcode = 0;
        int len = key.length();
    
        for (int i = 0; i < len; i++) {
            hashcode += key[i] * pow(33, len-i-1);
        }
    
        hashcode = hashcode%HASH_SIZE;
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

