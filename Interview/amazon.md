# Amazon

+ given an array of number, return an array that each elem equal to the multipilication of all the elem of the original array expect the elem at the same index as this elem's, in O(n) time.
    * walk through from left to right, to get the multiplication of all the elems on the left
    * walk through from right to left, to get the multiplication of all the elems on the right
    * gen the result for each elem