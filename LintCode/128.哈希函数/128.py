class Solution:
    """
    @param key: A String you should hash
    @param HASH_SIZE: An integer
    @return an integer
    """
    def hashCode(self, key, HASH_SIZE):
        sum = 0
        for char in key:
            sum = sum * 33 + ord(char)
            sum = sum % HASH_SIZE
        return sum