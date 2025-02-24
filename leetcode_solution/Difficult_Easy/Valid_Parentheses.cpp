/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sts;
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                sts.push(c);
            }else{
                if(sts.empty()||!isMatch(c,sts.top())){
                    return false;
                }
                sts.pop();
            }
        }
        return sts.empty();
    }

private:
    bool isMatch(char last, char first){
        return (last=='}'&&first=='{')||(last==')'&&first=='(')||(last==']'&&first=='[');
    }
};