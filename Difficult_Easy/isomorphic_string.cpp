/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    bool isomorphString(string s, string t)  {
        vector<int> indexS(200,0);
        vector<int> indexT(200,0);

        int len = s.length();
        if(len!=t.length()){
          return false;
        }
        for(int i=0;i<len;i++){
          if(indexS[s[i]]!=indexT[t[i]]){
            return false;
          }
          indexS[s[i]] = i+1;
          indexT[t[i]] = i+1;
        }
        return true;
    }
};

// Time complexity: O(n), where n is the length of the strings.
// Space complexity: O(n), where n is the number of unique characters in the strings.