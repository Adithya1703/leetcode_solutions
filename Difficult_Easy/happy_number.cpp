/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:1 <= n <= 231 - 1
*/

#include<unordered_set>
using namespace std;

class Solution{
  public:
      int getnext(int n){
          int sum = 0;
          while(n>0){
              int digit = n%10;
              n = n/10;
              sum += digit*digit;
          }
          return sum;
      }
      bool isHappy(int n){
          int slow = n;
          int fast = getnext(n);
          while(fast !=1 && slow != fast){
              slow = getnext(slow); // Move slow pointer by one step (next sum of squares)
              fast = getnext(getnext(fast)); // Move fast pointer by two steps (next sum of squares, twice)
          }
          return fast==1; // if fast pointer reaches 1, then return true
      }

      // Time complexity - O(log n) - as we are dividing the number by 2 in each iteration - log(base2) n
      // Space complexity - O(1) - as we are not using any extra space

      // We can also solve this using unordered set
      bool isHappy(int n){
          unordered_set<int> seen;
          while(n !=1 && seen.find(n) == seen.end()){
              seen.insert(n);
              n = getnext(n);
          }
          return n==1; // if fast pointer reaches 1, then return true
      }

      // Time complexity - O(log n) - as we are dividing the number by 2 in each iteration - log(base2) n
      // Space complexity - O(log n) - as we are using unordered set to store the numbers we have seen
};