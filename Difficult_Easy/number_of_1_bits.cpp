/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

Constraints:

1 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;

// brute force - Convert the number to binary and count how many bits are 1.
// Time complexity - O(log n) - as we are dividing the number by 2 in each iteration - log(base2) n
// Space complexity - O(1) - as we are not using any extra space

class Solution{
  public:
      int hammingWeight(uint32_t n){
          int count = 0;
          while(n>0){
            if(n%2==1){
              count++;
            }
            n = n/2;
          }
          return count;
      }
};

// Brian Kernighan's Algorithm - This algorithm works by turning off the rightmost set bit of the number in each iteration.

class Solution {
  public:
      int hammingWeight(int n) {
          int count = 0;
          while(n>0){
              n = n & (n-1);
              count++;
          }
          return count;
      }
};