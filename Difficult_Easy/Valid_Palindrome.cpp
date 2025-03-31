/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

/*
Brute force - iterate through string to remove non alphanumeric chars and lowercase them
and then verfiy palindrome
*/

#include <iostream>
using namespace std;

class Solution{
public:
  bool isPalindrome(string s){
    string arr = "";
    for(int i=0;i<s.size();i++){
      char c = s[i];

      if (c >= 'A' && c <= 'Z') {  
        c += 32;  // Convert uppercase to lowercase
      }

      // Keep only alphanumeric characters (0-9, a-z)
      if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        arr += c; // Append valid character
      }
    }

    int n = arr.size();
    for(int i=0;i<n;i++){
      if(arr[i]!=arr[n-1-i]){
        return false;
      }
    }
    return true;
  }

};