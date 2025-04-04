/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

//cpp - time complexity - O(N)
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
      string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string output = "";
        int carry = 0;
        while(i>=0||j>=0||carry){
          int sum = carry;
          if(i>=0) sum+=a[i--]+'0';
          if(j>=0) sum+=b[j--]+'0';
          carry = sum/2;
          output.insert(output.begin(),(sum%2)+'0');
        }
        return output;
      }
  };