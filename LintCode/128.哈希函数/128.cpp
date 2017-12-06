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
        long double hashcode = 0;
        int len = key.length();
    
        for (int i = 0; i < len; i++) {
            // cout << "i - " << i << ", key[i] - " << key[i] << ", " << pow(33, len-i-1) << endl;
            hashcode += key[i] * powl(33, (long double)(len-i-1));
        }
        
        // cout << hashcode<<endl;
        hashcode = fmod(hashcode, (long double) HASH_SIZE);
        // cout << hashcode<<endl;
        return hashcode;
    }
};

int main() {
    string str = "abcdefghijklmnopqrstuvwxyz";
    int HASH_SIZE = 2607;
    
    Solution sol;
    int hash = sol.hashCode(str, HASH_SIZE);
    cout<<hash<<endl;

    return 0;
}

