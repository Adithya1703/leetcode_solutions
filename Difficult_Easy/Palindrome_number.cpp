/*Question: Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1*/


//Code in CPP

//Brute approach - reverse it and check whether revrse and main number are same - O(log x) in space complexity - to store digits in vector

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
			bool isPalindrome(int x) {
					if (x < 0) return false;
	
					vector<int> digits;
					while (x > 0) {
							digits.push_back(x % 10); // Extract last digit
							x /= 10;
					}
	
					int n = digits.size();
					for (int i = 0; i < n / 2; i++) {
							if (digits[i] != digits[n - 1 - i]) return false;
					}
					return true;
			}
	};
//optimal approach:

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};


